#include "pipex_bonus.h"

void	here_doc(char **av, t_pipbonus *pipex)
{
	char	*tmp;
	int		fd;

	fd = open(".here_doc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		print_error("Message d'erreur");// changer le message d'erreur !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	while (1)
	{
		write(1, "heredoc>", 9);
		tmp = get_next_line(0);
		// printf(":%s:\n", tmp);
		if (!ft_strncmp(tmp, av[2], ft_strlen(tmp) - 1))
		{
			printf("%d\n", ft_strncmp(tmp, av[2], ft_strlen(tmp) - 1));
			break;
		}
		write(fd, tmp, ft_strlen(tmp));
		write(fd, "\n", 1);
		free(tmp);
	}
	free(tmp);
	close(fd);
	pipex->file1 = open(".here_doc_tmp", O_RDONLY);
	if (pipex->file1 < 0)
	{
		unlink(".here_doc_tmp");
		perror("Error file 1 :");
		exit(EXIT_FAILURE);
	}
}

void	init_files(char **av, int ac, t_pipbonus *pipex)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		here_doc(av, pipex);
	else
	{
		pipex->file1 = open(av[1], O_RDONLY);
		if (pipex->file1 < 0)
		{
			perror("Error first file ");
			exit(EXIT_FAILURE);
		}
	}
	pipex->file2 = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->file2 < 0)
	{
		perror("Error second file ");
		close(pipex->file1);
		exit(EXIT_FAILURE);
	}
}

void	init_cmds(char **av, int ac, t_pipbonus *pipex)
{
	int	i;
	int	j;

	pipex->cmds = malloc(sizeof(char **) * (pipex->nbscmds + 1));
	pipex->cmds[pipex->nbscmds - 1] = 0;
	if (!pipex->cmds)
	{
		// freeee
	}
	j = 0;
	i = 2 + pipex->here_doc;
	while (i < ac - 1)
	{
		pipex->cmds[j] = ft_split(av[i], ' ');
		if (!pipex->cmds[j])
		{
			ft_putendl_fd("Malloc error\n", 2);
			ft_exit(pipex, 2);
		}
		if (!pipex->cmds[j][0])
		{
			ft_putstr_fd("pipex: command number ", 2);
			ft_putnbr_fd(j + 1, 2);
			ft_putstr_fd(" is null\n", 2);
			ft_exit(pipex, 2);
		}
		i++;
		j++;
	}
}

void	init_path(char **envp, t_pipbonus *pipex)
{
	int		i;

	pipex->path = malloc(sizeof(char *) * (pipex->nbscmds + 1));
	if (!pipex->path)
	{
		//FAIRE QUELQUE CHOSE BOZO!!!!
		print_error("BOZZZZZZZZZZZZZZO");
	}
	i = 0;
	while (pipex->cmds[i])
	{
		pipex->path[i] = "salut";
	// printf("%s\n", get_path(pipex->cmds[i][0], envp));
		pipex->path[i] = get_path(pipex->cmds[i][0], envp);
		if (!pipex->path[i])
		{
			//FAIT UNE FONCTION QUI FREE TOUT ET PLUS VITE QUE ÇA STEUPLAIT
			print_error("Erreur lors de la creation du path");
		}
		i++;
	}
	pipex->path[i] = 0;
}
