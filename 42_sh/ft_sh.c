/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 09:48:00 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/14 16:59:21 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int		ft_verif_cd_setenv_unsetenv(t_sh sh)
{
	if (ft_strcmp(sh.arg, "cd") == 0 || ft_strcmp(sh.arg, "setenv") == 0
		|| ft_strcmp(sh.arg, "unsetenv") == 0
		|| (ft_strcmp(sh.arg, "env") == 0
			&& (sh.av[1] == '\0' || ft_strcmp(sh.av[1], "-i") == 0)))
		return (0);
	return (1);
}

static t_sh		ft_exe_sh(t_sh sh)
{
	if (ft_strcmp(sh.line, "") && ft_exit(sh.line))
	{
		sh.av = ft_strsplit_trim(sh.line);
		sh.arg = ft_strdup(sh.av[0]);
		if (ft_verif_cd_setenv_unsetenv(sh))
		{
			if (ft_strcmp(sh.arg, "env") == 0)
			{
				free(sh.arg);
				ft_free_double_tab(&sh.av);
				sh.av = ft_strsplit_trim(sh.line + 3);
				sh.arg = ft_strdup(sh.av[0]);
			}
			sh.path = ft_get_path(sh.envp, sh.arg);
			if (sh.path != NULL)
				ft_exe(sh, sh.envp);
			else
				ft_error(sh.arg);
		}
		else
			sh = ft_other_commande(sh);
	}
	return (sh);
}

static int		ft_verif_dup(char *line)
{
	int		count;

	count = 0;
	while (line[count])
	{
		if (line[count] == '|' || line[count] == '<' || line[count] == '>')
			return (1);
		count++;
	}
	return (0);
}

static t_sh		ft_commande(t_sh sh)
{
	char	**comma;
	int		count;

	if (ft_strcmp(sh.line, ""))
		sh.line = ft_strtrim(sh.line);
	count = 0;
	comma = ft_strsplit(sh.line, ';');
	free(sh.line);
	while (comma[count])
	{
		sh.line = ft_strdup(comma[count]);
		if (ft_verif_dup(sh.line) == 0)
			sh = ft_exe_sh(sh);
		else
			ft_dup(sh.line, sh.envp);
		sh = ft_free_sh(sh);
		free(sh.line);
		count++;
	}
	ft_prompt();
	ft_free_double_tab(&comma);
	return (sh);
}

void			ft_sh(char **envp)
{
	t_sh	sh;

	sh.envp = ft_copy_envp(envp);
	sh = ft_init_sh(sh);
	ft_prompt();
	while (get_next_line(0, &sh.line) == 1)
	{
		while (ft_strcmp(sh.line, "\\") == 0)
		{
			ft_putstr("> ");
			free(sh.line);
			get_next_line(0, &sh.line);
		}
		sh = ft_commande(sh);
	}
}
