/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:24:23 by carlos            #+#    #+#             */
/*   Updated: 2022/10/07 16:48:59 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	tab = malloc(nmemb * size);
	if (!tab || size == SIZE_MAX || nmemb == SIZE_MAX)
		return (0);
	ft_bzero(tab, nmemb * size);
	return (tab);
}
