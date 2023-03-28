/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:48:56 by carlosortiz       #+#    #+#             */
/*   Updated: 2023/03/28 23:59:29 by carlosortiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(char **av, t_pipbonus *pipex)
{
	char	*tmp;
	int		fd;
	size_t	len;

	fd = open(".here_doc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		ft_exit(pipex, 1, 1);
	while (1)
	{
		write(1, "heredoc>", 9);
		tmp = get_next_line(0);
		len = ft_strlen(tmp) - 1;
		if (!ft_strncmp(tmp, av[2], len) && (len == ft_strlen(av[2])))
			break ;
		write(fd, tmp, ft_strlen(tmp));
		write(fd, "\n", 1);
		free(tmp);
	}
	free(tmp);
	close(fd);
	pipex->file1 = open(".here_doc_tmp", O_RDONLY);
	if (pipex->file1 < 0)
		ft_exit(pipex, 1, 1);
}

void	init_files(char **av, int ac, t_pipbonus *pipex)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		here_doc(av, pipex);
	else
	{
		pipex->file1 = open(av[1], O_RDONLY);
		if (pipex->file1 < 0)
			ft_exit(pipex, 1, 1);
	}
	if (pipex->here_doc)
		pipex->file2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		pipex->file2 = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->file2 < 0)
		ft_exit(pipex, 1, 1);
}

void	init_cmds(char **av, int ac, t_pipbonus *pipex)
{
	int	i;
	int	j;

	pipex->cmds = malloc(sizeof(char **) * (pipex->nbscmds + 1));
	if (!pipex->cmds)
		ft_exit(pipex, 1, 0);
	pipex->cmds[pipex->nbscmds] = NULL;
	j = -1;
	i = 1 + pipex->here_doc;
	while (++i < ac - 1)
	{
		pipex->cmds[++j] = ft_split(av[i], ' ');
		if (!pipex->cmds[j])
		{
			ft_putendl_fd("Malloc error\n", 2);
			ft_exit(pipex, 1, 0);
		}
		if (!pipex->cmds[j][0])
		{
			ft_putstr_fd("pipex: Command number ", 2);
			ft_putnbr_fd(j + 1, 2);
			ft_putstr_fd(" is null\n", 2);
			ft_exit(pipex, 1, 0);
		}
	}
}

void	init_path(char **envp, t_pipbonus *pipex)
{
	int		i;

	pipex->path = malloc(sizeof(char *) * (pipex->nbscmds + 1));
	if (!pipex->path)
	{
		ft_putstr_fd("Malloc Error\n", 2);
		ft_exit(pipex, 1, 0);
	}
	pipex->path[pipex->nbscmds] = 0;
	i = 0;
	while (pipex->cmds[i])
	{
		pipex->path[i] = get_path(pipex->cmds[i][0], envp);
		if (!pipex->path[i])
		{
			ft_putstr_fd("pipex: command not found: ", 2);
			ft_putstr_fd(pipex->cmds[i][0], 2);
			ft_putstr_fd("\n", 2);
			ft_exit(pipex, 1, 0);
		}
		i++;
	}
}
