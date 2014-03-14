/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_prompt_exe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 10:48:40 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/11 16:29:09 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			ft_prompt(void)
{
	char	buff[256];
	char	*pwd;
	int		i;

	i = 0;
	pwd = getcwd(buff, sizeof(buff));
	while (pwd[i] != '\0')
		i++;
	while (pwd[i] != '/')
		i--;
	write(1, &pwd[i], ft_strlen(&pwd[i]));
	write(1, " ", 1);
}

static char		**ft_get_path_comp(char **envp)
{
	char	**path_comp;
	char	*temp;
	int		i;

	path_comp = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path_comp = ft_strsplit(envp[i], ':');
		i++;
	}
	if (path_comp)
	{
		temp = path_comp[0];
		path_comp[0] = ft_strdup(temp + 5);
		free(temp);
	}
	return (path_comp);
}

static char		*ft_path(char *arg)
{
	char	*path;

	path = ft_strdup(arg);
	return (path);
}

char			*ft_get_path(char **envp, char *arg)
{
	char	**path_comp;
	char	*path;
	int		i;

	if (arg[0] == '/' || ft_strncmp("./", arg, 2) == 0)
		return (ft_path(arg));
	path_comp = ft_get_path_comp(envp);
	i = 0;
	arg = ft_strjoin("/", arg);
	while (path_comp && path_comp[i] != '\0')
	{
		path = ft_strjoin(path_comp[i], arg);
		if ((access(path, F_OK) == 0) && (access(path, R_OK) == 0)
			&& (access(path, X_OK) == 0))
		{
			ft_free_double_tab(&path_comp);
			free(arg);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_double_tab(&path_comp);
	free(arg);
	return (NULL);
}

void			ft_exe(t_sh sh, char **envp)
{
	pid_t	father;

	if (ft_strncmp(sh.arg, "./", 2) == 0)
		sh.path = sh.path + 2;
	father = fork();
	if (father > 0)
		wait(0);
	else
		if (execve(sh.path, sh.av, envp) == -1)
		{
			ft_error(sh.arg);
			exit(0);
		}
}
