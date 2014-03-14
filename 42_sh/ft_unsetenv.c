/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 14:59:32 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/03 15:59:00 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char		**ft_write_unsetenv(char **envp, char *suppr, int *k)
{
	int		i;
	int		j;
	char	**new_envp;

	new_envp = (char **)malloc(sizeof(char *) * ft_strlen2(envp));
	i = 0;
	j = 0;
	while (envp[i] != NULL)
	{
		if (ft_comp(envp[i], suppr))
		{
			new_envp[j] = ft_strdup(envp[i]);
			j++;
		}
		i++;
	}
	ft_free_double_tab(&envp);
	new_envp[j] = NULL;
	*k = -1;
	return (new_envp);
}

char			**ft_unsetenv(char **envp, char *line)
{
	char	**av;
	int		i;
	int		j;

	av = ft_strsplit_trim(line);
	if (av[1] == '\0')
	{
		ft_free_double_tab(&av);
		write(1, "too few arguments\n", 18);
		return (envp);
	}
	i = 1;
	while (av[i] != '\0')
	{
		j = 0;
		while (j != -1 && envp[j] != NULL)
		{
			if (ft_comp(envp[j], av[i]) == 0)
				envp = ft_write_unsetenv(envp, av[i], &j);
			j++;
		}
		i++;
	}
	ft_free_double_tab(&av);
	return (envp);
}
