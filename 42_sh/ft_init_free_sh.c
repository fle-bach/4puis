/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_free_sh.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 13:45:41 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/03 15:54:53 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_sh	ft_init_sh(t_sh sh)
{
	sh.path = NULL;
	sh.arg = NULL;
	sh.av = NULL;
	return (sh);
}

t_sh	ft_free_sh(t_sh sh)
{
	if (sh.av)
	{
		ft_free_double_tab(&sh.av);
		sh.av = NULL;
	}
	if (sh.path)
	{
		free(sh.path);
		sh.path = NULL;
	}
	if (sh.arg)
	{
		free(sh.arg);
		sh.arg = NULL;
	}
	return (sh);
}
