#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_pipbonus
{
	int		file1;
	int		file2;
	int		here_doc;
	int		nbscmds;
	int		*pids;
	int		**pipes;
	char	**path;
	char	***cmds;
}	t_pipbonus;

void	print_error(char *str);
void	free_tab(char **tab);
void	close_pipes(t_pipbonus *pipex, int i);
void	free_pipes(int **tab);
char	*get_all_path(char **envp);
char	*get_path(char *cmd, char **envp);
void	init_files(char **av, int ac, t_pipbonus *pipex);
void	init_cmds(char **av, int ac, t_pipbonus *pipex);
void	init_path(char **envp, t_pipbonus *pipex);
void	ft_exit(t_pipbonus *pip, int exitc, int want);

#endif