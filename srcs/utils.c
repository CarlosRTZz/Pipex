/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:49:26 by carlosortiz       #+#    #+#             */
/*   Updated: 2023/03/28 23:49:26 by carlosortiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	print_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit (1);
}

void	end_struct(t_pipex *pipex)
{
	close(pipex->file1);
	close(pipex->file2);
	free(pipex->path1);
	free(pipex->path2);
	free_tab(pipex->command1);
	free_tab(pipex->command2);
}
