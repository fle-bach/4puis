/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 15:40:12 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/06 12:49:42 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int		ft_verif(char *line)
{
	int		count;
	int		verif;

	count = 0;
	verif = 0;
	while (line[count])
	{
		if (line[count] == '|' && verif == 0)
			verif = 1;
		if (line[count] == '<' || line[count] == '>')
			verif = 2;
		count++;
	}
	if (verif == 1 && line[0] == '|')
		return (write(1, "parse error near `|'\n", 21));
	if (verif == 1 && line[count - 1] == '|')
		verif = 3;
	return (verif);
}

static char		*ft_pipe_end(char *line)
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

static int		ft_verif_pipe(char *line)
{
	int		count;
	int		save;
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

t_sh			ft_dup(t_sh sh)
{
	int		verif;

	verif = ft_verif(sh.line);
	if (verif == 3)
	{
		sh.line = ft_pipe_end(sh.line);
		verif = 1;
	}
	if (verif == 1 && ft_verif_pipe(sh.line) == 0)
		sh = ft_pipe(sh);
	else if (verif == 2)
		ft_putendl("non gerer");
	return (sh);
}
