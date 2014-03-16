/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 16:22:29 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/14 16:50:11 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			ft_verif_pipe(char *line)
{
	int	count;
	int	save;
	char	*arg;

	count = 0;
	save = count;
	while (line[count])
	{
		if (line[count] == '|')
		{
			arg = ft_strsub(line, save, (count - save));
			arg = ft_strtrim(arg);
			if (ft_strcmp(arg, "") == 0)
			{
				free(arg);
				return (write(1, "parse error near `|'\n", 21));
			}
			free(arg);
			save = count + 1;
		}
		count++;
	}
	return (0);
}

char			*ft_pipe_end(char *line)
{
	char	*pipe;
	char	*save;

	pipe = ft_strdup("");
	while (ft_strcmp(pipe, "") == 0)
	{
		free(pipe);
		ft_putstr("pipe> ");
		get_next_line(0, &pipe);
		pipe = ft_strtrim(pipe);
	}
	save = ft_strdup(line);
	free(line);
	line = ft_strjoin(save, pipe);
	free(pipe);
	free(save);
	return (line);
}

static t_sh		ft_sh_init(char *commande, t_sh sh, char **envp)
{
	sh = ft_init_sh(sh);
	sh.av = ft_strsplit_trim(commande);
	sh.arg = ft_strdup(sh.av[0]);
	sh.path = ft_get_path(envp, sh.arg);
	if (sh.path == NULL)
		ft_error(sh.arg);
	return (sh);
}

static void		ft_pipe1(char **commandes, char **envp, int count)
{
	pid_t	second;
	int		pfd[2];
	t_sh	sh1;

	sh1 = ft_sh_init(commandes[count], sh1, envp);
	pipe(pfd);
	second = fork();
	if (second > 0)
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		if (commandes[count + 2] != '\0')
			ft_pipe1(commandes, envp, (count + 1));
		wait(0);
	}
	else if (second == -1)
		ft_putendl("error");
	else
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		if (sh1.path != NULL)
			execve(sh1.path, sh1.av, envp);
		exit(0);
	}
}

t_sh			ft_pipe(t_sh sh)
{
	pid_t	first;
	char	**commandes;
	int		count;

	commandes = ft_strsplit(sh.line, '|');
	count = 0;
	while (commandes[count])
		count++;
	sh = ft_sh_init(commandes[count - 1], sh, sh.envp);
	first = fork();
	if (first > 0)
	{
		wait(0);
		ft_free_double_tab(&commandes);
	}
	else if (first == -1)
		ft_putendl("error");
	else
	{
		ft_pipe1(commandes, sh.envp, 0);
		if (sh.path != NULL)
			execve(sh.path, sh.av, sh.envp);
		exit(0);
	}
	return (sh);
}
