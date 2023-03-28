/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:37:17 by cortiz            #+#    #+#             */
/*   Updated: 2023/03/28 03:37:49 by carlosortiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include "libft.h"
# include <errno.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		pid1;
	int		pid2;
	int		file1;
	int		file2;
	int		pipe[2];
	char	**command1;
	char	**command2;
	char	*path1;
	char	*path2;
}	t_pipex;

char	*get_path(char *cmd, char **envp);
void	create_child(t_pipex pipex, char **envp);
void	create_child2(t_pipex pipex, char **envp);
void	free_tab(char **tab);
void	print_error(char *str);
void	end_struct(t_pipex *pipex);

#endif