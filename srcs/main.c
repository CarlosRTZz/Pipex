/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:36:14 by cortiz            #+#    #+#             */
/*   Updated: 2023/03/28 03:46:19 by carlosortiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_files(t_pipex *pipex, char **av)
{
	pipex->file1 = open(av[1], O_RDONLY);
	if (pipex->file1 < 0)
	{
		perror("Error infile ");
		exit(EXIT_FAILURE);
	}
	pipex->file2 = open(av[4], O_RDWR | O_TRUNC | O_CREAT, 0664);
	if (pipex->file2 < 0)
	{	
		close(pipex->file1);
		perror("Error outfile ");
		exit(EXIT_FAILURE);
	}
	if (pipe(pipex->pipe) == -1)
	{
		close(pipex->file1);
		close(pipex->file2);
		perror("Pipe error ");
		exit(EXIT_FAILURE);
	}
}

void	init_cmd(t_pipex *pipex, char **av)
{
	pipex->command1 = ft_split(av[2], ' ');
	if (!*pipex->command1)
	{
		close(pipex->file1);
		close(pipex->file2);
		close(pipex->pipe[0]);
		close(pipex->pipe[1]);
		print_error("First command is NULL");
	}
	pipex->command2 = ft_split(av[3], ' ');
	if (!*pipex->command2)
	{
		close(pipex->file1);
		close(pipex->file2);
		close(pipex->pipe[0]);
		close(pipex->pipe[1]);
		free_tab(pipex->command1);
		print_error("Second command is NULL");
	}
}

void	init_path(t_pipex *pipex, char **envp)
{
	pipex->path1 = get_path(pipex->command1[0], envp);
	if (pipex->path1 == 0)
	{
		close(pipex->file1);
		close(pipex->file2);
		close(pipex->pipe[0]);
		close(pipex->pipe[1]);
		free_tab(pipex->command1);
		free_tab(pipex->command2);
		print_error("First command doesn't exist");
	}
	pipex->path2 = get_path(pipex->command2[0], envp);
	if (pipex->path2 == 0)
	{
		free(pipex->path1);
		close(pipex->file1);
		close(pipex->file2);
		close(pipex->pipe[0]);
		close(pipex->pipe[1]);
		free_tab(pipex->command1);
		free_tab(pipex->command2);
		print_error("Second command doesn't exist");
	}
}

void	init_pipe(t_pipex *pipex, char **av, char **envp)
{
	init_files(pipex, av);
	init_cmd(pipex, av);
	init_path(pipex, envp);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
		print_error("Wrong numbers of args");
	init_pipe(&pipex, av, envp);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		create_child(pipex, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		create_child2(pipex, envp);
	close(pipex.pipe[0]);
	close(pipex.pipe[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	end_struct(&pipex);
}
