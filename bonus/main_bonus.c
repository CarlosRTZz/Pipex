/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:48:46 by carlosortiz       #+#    #+#             */
/*   Updated: 2023/03/30 22:43:38 by carlosortiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_args(int ac, char **av, t_pipbonus *pipex)
{
	if (ac == 1)
		ft_exit(pipex, 1, 0);
	if (!ft_strncmp("here_doc", av[1], 8) && (ft_strlen(av[1]) == 8))
		pipex->here_doc = 1;
	else
		pipex->here_doc = 0;
	if (ac < 5 + pipex->here_doc)
	{
		ft_putstr_fd("Wrong number of arguments\n", 2);
		ft_exit(pipex, 1, 0);
	}
}

void	close_pipes(t_pipbonus *pipex, int n)
{
	while (--n >= 0 && pipex->pipes[n])
	{
		close(pipex->pipes[n][0]);
		close(pipex->pipes[n][1]);
	}
}

void	init_pipes(t_pipbonus *pipex)
{
	int	i;

	i = 0;
	pipex->pipes = malloc(sizeof(int *) * (pipex->nbscmds));
	if (!pipex->pipes)
	{
		ft_putstr_fd("Malloc Error\n", 2);
		ft_exit(pipex, 1, 0);
	}
	pipex->pipes[pipex->nbscmds - 1] = NULL;
	while (i < pipex->nbscmds - 1)
	{
		pipex->pipes[i] = malloc(sizeof(int) * 2);
		if (!pipex->pipes[i])
		{
			ft_putstr_fd("Malloc Error\n", 2);
			ft_exit(pipex, 1, 0);
		}
		ft_memset(pipex->pipes[i], 0, sizeof(int) * 2);
		if (pipe(pipex->pipes[i]) == -1)
			ft_exit(pipex, 1, 1);
		i++;
	}
}

void	create_child(t_pipbonus *pipex, char **envp, int i)
{
	pipex->pids[i] = fork();
	if (pipex->pids[i] == 0)
	{
		if (i == 0)
		{
			dup2(pipex->pipes[i][1], 1);
			dup2(pipex->file1, 0);
		}
		else if (i == pipex->nbscmds - 1)
		{
			dup2(pipex->pipes[i - 1][0], 0);
			dup2(pipex->file2, 1);
		}
		else
		{
			dup2(pipex->pipes[i - 1][0], 0);
			dup2(pipex->pipes[i][1], 1);
		}
		close_pipes(pipex, pipex->nbscmds - 1);
		execve(pipex->path[i], pipex->cmds[i], envp);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipbonus	pipex;
	int			i;

	i = -1;
	ft_memset(&pipex, 0, sizeof(t_pipbonus));
	check_args(ac, av, &pipex);
	pipex.nbscmds = ac - 3 - pipex.here_doc;
	init_files(av, ac, &pipex);
	init_pipes(&pipex);
	init_cmds(av, ac, &pipex);
	init_path(envp, &pipex);
	pipex.pids = malloc(sizeof(int) * (pipex.nbscmds + 1));
	if (!pipex.pids)
	{
		ft_putstr_fd("Malloc error\n", 2);
		ft_exit(&pipex, 1, 0);
	}
	while (++i < pipex.nbscmds)
		create_child(&pipex, envp, i);
	close_pipes(&pipex, pipex.nbscmds - 1);
	waitpid(-1, NULL, 0);
	ft_exit(&pipex, 0, 0);
}
