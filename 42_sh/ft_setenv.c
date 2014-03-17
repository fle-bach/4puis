/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 15:34:46 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/17 12:39:27 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char			**ft_new_envp(char **envp, char **av)
{
	char	**new_envp;
	int		count;

	count = 0;
	while (envp[count])
		count++;
	new_envp = (char **)malloc(sizeof(char *) * (count + 2));
	count = 0;
	while (envp[count])
	{
		new_envp[count] = ft_strdup(envp[count]);
		count++;
	}
	new_envp[count] = ft_strjoin(av[1], "=");
	if (av[2] != '\0')
		new_envp[count] = ft_strjoin(new_envp[count], av[2]);
	new_envp[count + 1] = NULL;
	ft_free_double_tab(&envp);
	return (new_envp);
}

int				ft_comp(char *envp, char *av)
{
	char	**bis;

	bis = ft_strsplit(envp, '=');
	if (ft_strcmp(bis[0], av) == 0)
	{
		ft_free_double_tab(&bis);
		return (0);
	}
	ft_free_double_tab(&bis);
	return (1);
}

static char		**ft_envp1(char **envp, char **av)
{
	int		count;

	if (ft_error_arg(av[1]) == -1)
		return (envp);
	count = 0;
	while (envp[count])
	{
		if (ft_comp(envp[count], av[1]) == 0)
		{
			free(envp[count]);
			envp[count] = ft_strjoin(av[1], "=");
			return (envp);
		}
		count++;
	}
	return (ft_new_envp(envp, av));
}

static char		**ft_envp2(char **envp, char **av)
{
	int		count;

	if (ft_error_arg(av[1]) == -1)
		return (envp);
	count = 0;
	while (envp[count])
	{
		if (ft_comp(envp[count], av[1]) == 0)
		{
			free(envp[count]);
			envp[count] = ft_strjoin(av[1], "=");
			envp[count] = ft_strjoin(envp[count], av[2]);
			return (envp);
		}
		count++;
	}
	return (ft_new_envp(envp, av));
}

char			**ft_setenv(char **envp, char *line)
{
	char	**av;

	av = ft_strsplit_trim(line);
	if (av[1] == '\0')
		ft_env(envp);
	else if (av[2] == '\0')
		envp = ft_envp1(envp, av);
	else if (av[3] == '\0')
		envp = ft_envp2(envp, av);
	else
		write(2, "too many argument\n", 18);
	ft_free_double_tab(&av);
	return (envp);
}
