/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:26:13 by cortiz            #+#    #+#             */
/*   Updated: 2022/10/13 11:18:31 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*sb1;
	unsigned char	*sb2;

	sb1 = (unsigned char *)s1;
	sb2 = (unsigned char *)s2;
	i = 0;
	while (sb1[i] == sb2[i] && i < n)
	{
		if (sb1[i] == '\0' && sb2[i] == '\0')
			return (0);
		i++;
	}
	if (i == n)
		return (0);
	return (sb1[i] - sb2[i]);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char a[] = "test\200";
	char b[] = "test\0";
	printf("%d\n", ft_strncmp(a, b, 6));
	printf("%d\n", strncmp(a, b, 6));
}
*/