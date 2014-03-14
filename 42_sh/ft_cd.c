/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 16:14:10 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/03 15:54:30 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char		*ft_found_oldpwd(char ***envp)
{
	int		count;
	char	*init_cd;
	char	buff[255];
	char	*pwd;

	count = 0;
	while (envp[0][count] != NULL)
	{
		if (ft_strncmp(envp[0][count], "OLDPWD=", 7) == 0)
		{
			if (ft_error_less(envp[0][count] + 7) == -1)
				return (NULL);
			pwd = getcwd(buff, sizeof(buff));
			init_cd = ft_strdup(envp[0][count] + 7);
			free(envp[0][count]);
			envp[0][count] = ft_strjoin("OLDPWD=", pwd);
			return (init_cd);
		}
		count++;
	}
	return (NULL);
}

static char		*ft_init_cd(t_sh sh)
{
	int		count;
	char	*init_cd;

	if (sh.av[1] != '\0' && sh.av[1][0] != '~')
		return (ft_strdup("not cd"));
	count = 0;
	while (sh.envp[count] != NULL)
	{
		if (ft_strncmp(sh.envp[count], "HOME=", 5) == 0)
		{
			init_cd = ft_strdup((sh.envp[count] + 5));
			if (init_cd[0] == '\0')
			{
				write(1, "home is empty\n", 14);
				return (NULL);
			}
			return (init_cd);
		}
		count++;
	}
	write(1, "home not found\n", 15);
	return (NULL);
}

static char		**ft_next_cd(t_sh sh, int error_tild, char *init_cd)
{
	char	*av_bis;

	if (error_tild == 0)
	{
		sh.envp = ft_change_oldpwd(sh.envp);
		if (chdir(sh.av[1]) == -1)
		{
			ft_putstr("permission denied: ");
			ft_putendl(sh.av[1]);
		}
	}
	else
	{
		av_bis = ft_strjoin(init_cd, sh.av[1] + 1);
		sh.envp = ft_change_oldpwd(sh.envp);
		if (chdir(av_bis) == -1)
		{
			ft_putstr("permission denied: ");
			ft_putendl(av_bis);
		}
		free(av_bis);
	}
	return (sh.envp);
}

static char		**ft_cd_less(t_sh sh)
{
	char	*init_cd;

	init_cd = ft_found_oldpwd(&sh.envp);
	if (init_cd)
	{
		if (chdir(init_cd) == -1)
		{
			ft_putstr("permission denied: ");
			ft_putendl(init_cd);
		}
		else
			ft_putendl(init_cd);
		free(init_cd);
	}
	else
		sh.envp = ft_change_oldpwd(sh.envp);
	return (sh.envp);
}

char			**ft_cd(t_sh sh)
{
	char	*init_cd;
	int		error_tild;

	if ((init_cd = ft_init_cd(sh)) == NULL || ft_error_cd(sh, init_cd) == -1)
		return (sh.envp);
	if (sh.av[1] == '\0' || ft_strcmp(sh.av[1], "~") == 0
		|| ft_strcmp(sh.av[1], "~/") == 0)
	{
		sh.envp = ft_change_oldpwd(sh.envp);
		if (chdir(init_cd) == -1)
		{
			ft_putstr("permission denied: ");
			ft_putendl(init_cd);
		}
	}
	else if (ft_strcmp(sh.av[1], "-") == 0)
		sh.envp = ft_cd_less(sh);
	else if ((error_tild = ft_error_tild(sh, init_cd)) != -1)
		sh.envp = ft_next_cd(sh, error_tild, init_cd);
	free(init_cd);
	return (ft_change_pwd(sh.envp));
}
