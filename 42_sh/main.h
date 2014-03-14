/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 09:30:24 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/05 16:59:38 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/stat.h>
#include <stdio.h>

typedef struct		s_sh
{
	char			*path;
	char			**av;
	char			*arg;
	char			*line;
	char			**envp;
}					t_sh;

t_sh	ft_other_commande(t_sh sh);
t_sh	ft_init_sh(t_sh sh);
t_sh	ft_free_sh(t_sh sh);
t_sh	ft_pipe(t_sh sh);
t_sh	ft_dup(t_sh sh);

char	**ft_unsetenv(char **envp, char *line);
char	**ft_new_envp(char **envp, char **av);
char	*ft_get_path(char **envp, char *arg);
char	**ft_setenv(char **envp, char *line);
char	**ft_change_oldpwd(char **envp);
char	**ft_change_pwd(char **envp);
char	**ft_copy_envp(char **envp);
char	**ft_cd(t_sh sh);

void	ft_exe(t_sh sh, char **envp);
void	ft_error(char *arg);
void	ft_env(char **envp);
void	ft_sh(char **envp);
void	ft_prompt(void);

int		ft_error_tild(t_sh sh, char *init_cd);
int		ft_error_cd(t_sh sh, char *init_cd);
int		ft_comp(char *envp, char *av);
int		ft_error_less(char *oldpwd);
int		ft_error_arg(char *arg);
int		ft_exit(char *line);

#endif /* !MAIN_H */
