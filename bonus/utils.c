#include "pipex_bonus.h"

void	print_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	free_pipes(int **tab)
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

char	*get_all_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			return (&envp[i][5]);
		i++;
	}
	return (0);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*tmp;
	char	*path;
	char	*all_path;
	char	**path_splited;

	i = -1;
	all_path = get_all_path(envp);
	if (!all_path)
		return (0);
	path_splited = ft_split(all_path, ':');
	while (path_splited[++i])
	{
		tmp = ft_strjoin(path_splited[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
		{
			free_tab(path_splited);
			return (path);
		}
		free(path);
	}
	free_tab(path_splited);
	return (NULL);
}
