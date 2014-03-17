/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 15:40:12 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/17 12:40:16 by fle-bach         ###   ########.fr       */
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
		return (write(2, "parse error near `|'\n", 21));
	else if (verif == 1 && line[count - 1] == '|')
		verif = 3;
	return (verif);
}

void			ft_other(t_sh sh)
{
	char	**cut;

	cut = ft_cut(sh);
	ft_env(cut);
	ft_free_double_tab(&cut);
}

void			ft_dup(char *line, char **envp)
{
	t_sh	sh;
	int		verif;

	sh = ft_init_sh(sh);
	sh.line = ft_strdup(line);
	sh.envp = envp;
	verif = ft_verif(sh.line);
	if (verif == 3)
	{
		sh.line = ft_pipe_end(sh.line);
		verif = 1;
	}
	if (verif == 1 && ft_verif_pipe(sh.line) == 0)
		sh = ft_pipe(sh);
	else if (verif == 2)
		ft_other(sh);
	free(sh.line);
	ft_free_sh(sh);
}
