/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:28:38 by cortiz            #+#    #+#             */
/*   Updated: 2023/03/26 18:52:00 by carlosortiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_all(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (0);
}

int	has_nl(char *str)
{
	size_t	i;

	i = -1;
	if (str)
		while (str[++i])
			if (str[i] == '\n')
				return (1);
	return (0);
}

size_t	ft_strlene(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		free(str);
		return (0);
	}
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoine(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*ret;

	size = ft_strlene(str1) + ft_strlene(str2);
	if (!size)
		return (free_all(&str1));
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (free_all(&str1));
	i = 0;
	j = 0;
	if (str1)
	{
		while (str1[i] && j < size)
			ret[j++] = str1[i++];
	}
	i = 0;
	while (str2[i] && j < size)
		ret[j++] = str2[i++];
	ret[j] = '\0';
	free(str1);
	return (ret);
}
