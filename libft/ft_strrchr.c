/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:44:13 by cortiz            #+#    #+#             */
/*   Updated: 2022/10/14 13:45:52 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*ret;

	ret = (char *)s;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if ((char)c == s[len])
			return (&ret[len]);
		len--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char tab[] = "salutluut";
	printf("%s\n", ft_strrchr(tab, 'l'));
	printf("%s\n", strrchr(tab, 'l'));
}
*/