/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:35:03 by cortiz            #+#    #+#             */
/*   Updated: 2022/10/05 18:58:49 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ret;
	int				i;

	ret = (unsigned char *)s;
	i = 0;
	while (n)
	{
		if (ret[i] == (unsigned char)c)
			return (&ret[i]);
		n--;
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char tab[] = "salutltoi";
	printf("%s\n", ft_memchr(tab, 'i', 10));
	printf("%s\n", memchr(tab, 'i', 10));
}
*/