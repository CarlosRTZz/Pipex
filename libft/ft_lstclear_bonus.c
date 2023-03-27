/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:03:55 by cortiz            #+#    #+#             */
/*   Updated: 2022/10/18 18:58:45 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clst;
	t_list	*nlst;

	if (!lst || !del)
		return ;
	clst = *lst;
	while (clst)
	{
		nlst = clst->next;
		del(clst->content);
		free(clst);
		clst = nlst;
	}
	*lst = 0;
}
