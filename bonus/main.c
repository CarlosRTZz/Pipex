#include "pipex_bonus.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void	check_args(int ac, char **av, t_pipbonus *pipex)
{
	if (!ft_strncmp("here_doc", av[1], 8))
		pipex->here_doc = 1;
	else
		pipex->here_doc = 0;
	if (ac < 5 + pipex->here_doc)
		ft_exit(pipex, 2);
		// print_error("Wrong number of arguments");
}

void	close_pipes(t_pipbonus *pipex, int n)
{
	int	i;

	i = 0;
	while (i <= n && pipex->pipes[i])
	{
		// if (pipex->pipes[i][0] != -1 && pipex->pipes[i][0] != 0)
			close(pipex->pipes[i][0]);
		// pipex->pipes[i][0] = -1;
		// if (pipex->pipes[i][0] != -1 && pipex->pipes[i][0] != 0)
			close(pipex->pipes[i][1]);
		// pipex->pipes[i][1] = -1;
		i++;
	}
}

void	init_pipes(t_pipbonus *pipex)
{
	int	i;

	i = 0;
	pipex->pipes = malloc(sizeof(int *) * (pipex->nbscmds));
	while (i < pipex->nbscmds - 1)
	{
		pipex->pipes[i] = malloc(sizeof(int) * 2);
		ft_memset(pipex->pipes[i], 0, sizeof(int) * 2);
		if (pipe(pipex->pipes[i]) == -1)
		{
			close(pipex->file1);
			close(pipex->file2);
			close_pipes(pipex, i);
			//FREEEEEEEEEEEEE
			perror("Pipe Error ");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	pipex->pipes[i] = NULL;
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
		if (execve(pipex->path[i], pipex->cmds[i], envp) == -1)
		{
			perror("Erreur ?");
			exit(EXIT_FAILURE);
		}
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipbonus	pipex;
	int			i;

	i = 0;
	ft_memset(&pipex, 0, sizeof(t_pipbonus));
	check_args(ac, av, &pipex);
	pipex.nbscmds = ac - 3 - pipex.here_doc;
	init_files(av, ac, &pipex);
	init_pipes(&pipex);
	init_cmds(av, ac, &pipex);// close les pipes et les files qui sont au dessus !!!!!! ET Gerer si malloc renvoie null IMPORTANT BATARD !!!!
	init_path(envp, &pipex);// FREE TOUT CE QUI EST AU DESSUS BATARD!!!
	// print_tab(pipex.path);
	// printf("%s\n", pipex.path[0]);
	pipex.pids = malloc(sizeof(int) * (pipex.nbscmds + 1));
	if (!pipex.pids)
		print_error("gere si ton malloc est null");// GERE SI TON MALLOC EST NULL!!!!!!!!!!!
	while (i < pipex.nbscmds)
	{
		printf("boucle : %d\n", i);
		create_child(&pipex, envp, i);
		i++;
	}
	close_pipes(&pipex, pipex.nbscmds - 1);
	waitpid(-1, NULL, 0);
	unlink(".here_doc_tmp");
	printf("s");
	// system("leaks pipex");
}
