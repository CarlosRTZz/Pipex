/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:45:03 by cortiz            #+#    #+#             */
/*   Updated: 2022/10/03 14:43:42 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

/*#include <ctype.h>
#include <stdio.h>
int main()
{
	char c;

	c = 'Q';
	printf("MAJ : %d\n", ft_isalpha(c));
	c = 'H';
	printf("autre Maj : %d\n", ft_isalpha(c));
	c = 'q';
	printf("min : %d\n", ft_isalpha(c));
	c = '+';
	printf("pas alph : %d\n", ft_isalpha(c));
}*/
