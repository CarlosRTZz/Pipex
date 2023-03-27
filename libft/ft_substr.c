/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:35:19 by cortiz            #+#    #+#             */
/*   Updated: 2022/10/18 16:50:56 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ret = malloc(sizeof(*ret) * (len + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}
/*
int main()
{
	const char *str = "salut";
	printf("%s", ft_substr(str, 2, 0));
}
*/