/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 17:52:16 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/03 15:54:42 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char		**ft_init_envp(void)
{
	char	buff[256];
	char	*path;
	char	*path_b;
	char	**envp;

	path_b = ft_strjoin("", "PATH=/usr/local/bin:/usr/bin:/bin:");
	path = ft_strjoin(path_b, "/usr/sbin:/sbin:/opt/X11/bin:/usr/texbin");
	free(path_b);
	envp = (char **)malloc(sizeof(char *) * 4);
	envp[0] = ft_strdup(path);
	envp[1] = ft_strjoin("PWD=", getcwd(buff, sizeof(buff)));
	envp[2] = ft_strjoin("OLDPWD=", getcwd(buff, sizeof(buff)));
	envp[3] = NULL;
	free(path);
	return (envp);
}

char			**ft_copy_envp(char **envp)
{
	int		i;
	char	**copy_envp;

	i = 0;
	while (envp[i] != NULL)
		i++;
	if (i == 0)
		return (ft_init_envp());
	copy_envp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		copy_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	copy_envp[i] = NULL;
	return (copy_envp);
}
