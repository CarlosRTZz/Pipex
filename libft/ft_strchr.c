/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:59:59 by cortiz            #+#    #+#             */
/*   Updated: 2022/10/18 12:01:48 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ret;

	ret = (char *)s;
	i = 0;
	while (s[i])
	{
		if ((char)c == s[i])
			return (&ret[i]);
		i++;
	}
	if (ret[i] == c)
		return (&ret[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char tab[] = "salut";
	printf("le mien : %s\n", ft_strchr(tab, 'z'));
	printf("le sien : %s\n", strchr(tab, 'z'));
}
*/