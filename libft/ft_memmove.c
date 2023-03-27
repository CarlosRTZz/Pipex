/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:01:08 by cortiz            #+#    #+#             */
/*   Updated: 2022/10/14 12:55:24 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	if (!dst && !src)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	i = -1;
	if (d < s)
	{
		while (++i < len)
			d[i] = s[i];
	}
	else
	{
		while (len)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	dst = d;
	return (dst);
}
/*#include <stdio.h>
int main()
{
	char tab[] = "Bonjour";
	char tab2[] = "Bonjour";
	char tab3[] = "Bonjour";

	memmove(tab2 + 3, tab2 + 2, 3);
	printf("memmove :    %s\n", tab2);
	ft_memmove(tab + 3, tab + 2, 3);
	printf("ft_memmove : %s\n", tab);
	ft_memcpy(tab3 + 3, tab3 + 2, 3);
	printf("ft_memcpy :  %s\n", tab3);
	return (0);
}*/