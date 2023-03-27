/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:49:44 by cortiz            #+#    #+#             */
/*   Updated: 2022/10/12 14:15:18 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	void	*odest;

	if (!dst && !src)
		return (dst);
	odest = dst;
	i = 0;
	while (i < n)
	{
		*(char *)dst = *(char *)src;
		i++;
		dst++;
		src++;
	}
	return (odest);
}
/*#include <stdio.h>
int main () 
{
   char src[50] = "wsh wsh";
   char dest[50];
   strcpy(dest,"Heloooo!!!!!!!!!!!!");
   printf("Before memcpy dest = %s\n", dest);
   //memcpy(dest, src, strlen(src)+1);
   printf("After memcpy dest = %s\n", memcpy(dest, src, strlen(src) + 1));
   
   return(0);
}*/
