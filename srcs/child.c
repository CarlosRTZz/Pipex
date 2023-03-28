#include "pipex.h"

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

void	create_child(t_pipex pipex, char **envp)
{
	dup2(pipex.pipe[1], 1);
	close(pipex.pipe[0]);
	dup2(pipex.file1, 0);
	execve(pipex.path1, pipex.command1, envp);
}

void	create_child2(t_pipex pipex, char **envp)
{
	dup2(pipex.pipe[0], 0);
	close(pipex.pipe[1]);
	dup2(pipex.file2, 1);
	execve(pipex.path2, pipex.command2, envp);
}
