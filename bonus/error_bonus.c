/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:48:52 by carlosortiz       #+#    #+#             */
/*   Updated: 2023/03/29 13:21:55 by carlosortiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_cmds(t_pipbonus *pip)
{
	int	i;

	i = -1;
	while (pip->cmds[++i])
		free_tab(pip->cmds[i]);
	free(pip->cmds);
}

void	ft_exit(t_pipbonus *pip, int exitc, int want)
{
	if (pip->file1 != -1 && pip->file1 != 0)
		close(pip->file1);
	if (pip->file2 != -1 && pip->file2 != 0)
		close(pip->file2);
	if (pip->pids)
		free(pip->pids);
	if (pip->pipes)
	{
		close_pipes(pip, pip->nbscmds - 1);
		free_tab((char **)pip->pipes);
	}
	if (pip->path)
		free_tab(pip->path);
	if (pip->cmds)
		free_cmds(pip);
	if (errno && (want == 1))
		perror("pipex ");
	unlink(".here_doc_tmp");
	exit(exitc);
}
