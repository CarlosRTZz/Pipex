/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:06:27 by carlos            #+#    #+#             */
/*   Updated: 2022/10/18 17:00:31 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	tab = NULL;
	return (tab);
}

int	count_word(const char *str, char sep)
{
	int	i;
	int	total_word;

	total_word = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == (const char)sep)
			i++;
		if (str[i] != '\0')
			total_word++;
		while (str[i] != (const char)sep && str[i])
			i++;
	}
	return (total_word);
}

char	*putin_col(const char *str, int new_word_size, int current_index)
{
	int		i;
	int		index;
	char	*tab;

	index = current_index - new_word_size;
	i = 0;
	tab = malloc(sizeof(char) * (new_word_size + 1));
	if (!tab)
		return (0);
	while (i < new_word_size)
	{
		tab[i] = str[index];
		i++;
		index++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**putin_raw(char **tab, const char *str, char sep, int total_word)
{
	int	i;
	int	new_word_size;
	int	tab_i;

	tab_i = 0;
	i = 0;
	while (tab_i < total_word)
	{
		new_word_size = 0;
		while (str[i] == (const char)sep)
			i++;
		while (str[i] != (const char)sep && str[i])
		{
			new_word_size++;
			i++;
		}
		tab[tab_i] = putin_col(str, new_word_size, i);
		if (!tab)
			return (ft_free(tab, tab_i));
		tab_i++;
	}
	return (tab);
}

char	**ft_split(char const *str, char sep)
{
	int		total_word;
	char	**tab;

	if (!str)
		return (NULL);
	total_word = count_word(str, sep);
	tab = malloc(sizeof(char *) * (total_word + 1));
	if (!tab)
		return (0);
	tab[total_word] = 0;
	tab = putin_raw(tab, str, sep, total_word);
	return (tab);
}
/*
#include <stdio.h>
int    main(int argc, char **argv)
{
    int        index;
    char    **split;
    (void)    argc;
    split = ft_split(argv[1], argv[2][0]);
    index = 0;
    while (split[index])
    {
        printf("%s\n", split[index]);
        index++;
    }
}
*/