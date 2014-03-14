/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:32:28 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/03 15:54:23 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int		ft_error_next_cd(t_sh sh, struct stat file)
{
	if (lstat(sh.av[1], &file))
	{
		ft_putstr("no such file or directory: ");
		ft_putendl(sh.av[1]);
		return (-1);
	}
	else if (S_ISDIR(file.st_mode))
		return (0);
	else
	{
		ft_putstr("not a directory: ");
		ft_putendl(sh.av[1]);
		return (-1);
	}
	return (0);
}

static int		ft_error_next_tild(char *av_bis, struct stat file)
{
	if (lstat(av_bis, &file))
	{
		ft_putstr("no such file or directory: ");
		ft_putendl(av_bis);
		return (-1);
	}
	else if (S_ISDIR(file.st_mode))
		return (1);
	else
	{
		ft_putstr("not a directory: ");
		ft_putendl(av_bis);
		return (-1);
	}
	return (1);
}

int				ft_error_less(char *oldpwd)
{
	struct stat		file;

	if (lstat(oldpwd, &file))
	{
		ft_putstr("no such file or directory: ");
		ft_putendl(oldpwd);
		return (-1);
	}
	else if (S_ISDIR(file.st_mode))
		return (0);
	else
	{
		ft_putstr("not a directory: ");
		ft_putendl(oldpwd);
		return (-1);
	}
	return (0);
}

int				ft_error_tild(t_sh sh, char *init_cd)
{
	struct stat		file;
	int				nb;
	char			*av_bis;

	if (sh.av[1][0] != '~')
		return (0);
	if (sh.av[1][1] != '/')
	{
		ft_putstr("no such user or named directory: ");
		ft_putendl(sh.av[1] + 1);
		return (-1);
	}
	av_bis = ft_strjoin(init_cd, (sh.av[1] + 1));
	nb = ft_error_next_tild(av_bis, file);
	free(av_bis);
	return (nb);
}

int				ft_error_cd(t_sh sh, char *init_cd)
{
	struct stat		file;

	if (ft_strcmp(init_cd, "not cd") != 0 || ft_strcmp(sh.av[1], "-") == 0)
		return (0);
	if (sh.av[2] != '\0' && sh.av[3] != '\0')
	{
		ft_putendl("too many argument");
		return (-1);
	}
	else if (sh.av[2] != '\0')
	{
		ft_putstr("string not in pwd: ");
		ft_putendl(sh.av[1]);
		return (-1);
	}
	return (ft_error_next_cd(sh, file));
}
