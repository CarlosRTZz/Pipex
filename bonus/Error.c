#include "pipex_bonus.h"

void	ft_exit(t_pipbonus *pip, int exitc)
{
	int	i;

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
	{
		i = 0;
		while (pip->cmds[i])
		{
			free_tab(pip->cmds[i]);
			i++;
		}
		free(pip->cmds);
	}
	if (errno)
		perror("pipex:");
	exit(exitc);
}