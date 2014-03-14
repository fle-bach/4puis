/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:59:22 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 17:59:23 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t	i;

	i = ft_strlen(s);
	write(fd, s, i);
	write(fd, "\n", 1);
}
