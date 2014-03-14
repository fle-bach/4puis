/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:01:34 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 18:01:35 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_startswith(const char *str, const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && str[i] == s[i])
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}
