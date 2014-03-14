/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_commande.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 11:42:43 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/03 16:00:33 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char		**ft_init_av(char *pwd, int i)
{
	char	**av;

	av = (char **)malloc(sizeof(char *) * 4);
	av[0] = ft_strdup("rien");
	if (i == 0)
		av[1] = ft_strdup("PWD");
	else
		av[1] = ft_strdup("OLDPWD");
	av[2] = ft_strdup(pwd);
	av[3] = '\0';
	return (av);
}

char			**ft_change_oldpwd(char **envp)
{
	int		count;
	char	buff[255];
	char	*pwd;
	char	**av;

	count = 0;
	pwd = getcwd(buff, sizeof(buff));
	while (envp[count] != NULL)
	{
		if (ft_strncmp(envp[count], "OLDPWD=", 7) == 0)
		{
			free(envp[count]);
			envp[count] = ft_strjoin("OLDPWD=", pwd);
			return (envp);
		}
		count++;
	}
	av = ft_init_av(pwd, 1);
	envp = ft_new_envp(envp, av);
	ft_free_double_tab(&av);
	return (envp);
}

char			**ft_change_pwd(char **envp)
{
	int		count;
	char	buff[255];
	char	*pwd;
	char	**av;

	count = 0;
	pwd = getcwd(buff, sizeof(buff));
	while (envp[count] != NULL)
	{
		if (ft_strncmp(envp[count], "PWD=", 4) == 0)
		{
			free(envp[count]);
			envp[count] = ft_strjoin("PWD=", pwd);
			return (envp);
		}
		count++;
	}
	av = ft_init_av(pwd, 0);
	envp = ft_new_envp(envp, av);
	ft_free_double_tab(&av);
	return (envp);
}

void			ft_env(char **envp)
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_putendl(envp[i]);
		i++;
	}
}

t_sh			ft_other_commande(t_sh sh)
{
	if (ft_strcmp(sh.arg, "cd") == 0)
		sh.envp = ft_cd(sh);
	else if (ft_strcmp(sh.arg, "setenv") == 0)
		sh.envp = ft_setenv(sh.envp, sh.line);
	else if (ft_strcmp(sh.arg, "env") == 0)
		ft_env(sh.envp);
	else
		sh.envp = ft_unsetenv(sh.envp, sh.line);
	return (sh);
}
