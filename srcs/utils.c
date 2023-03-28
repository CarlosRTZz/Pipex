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
