/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:46:55 by carlos            #+#    #+#             */
/*   Updated: 2022/10/14 15:34:42 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ischarset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		start;
	int		end;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ischarset(s1[start], set) == 1 && s1[start])
		start++;
	while (ischarset(s1[end], set) == 1 && (end > start))
		end--;
	if (((start - 1) - end) == 0)
	{
		ret = malloc(sizeof(char));
		if (!ret)
			return (0);
		ret[0] = '\0';
		return (ret);
	}
	ret = ft_substr(s1, start, (end - start) + 1);
	return (ret);
}
