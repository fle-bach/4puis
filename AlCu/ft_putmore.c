/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmore.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 10:41:48 by gleger            #+#    #+#             */
/*   Updated: 2014/03/08 12:47:56 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

void	ft_putstr_fd(const char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	ft_putchar_fd(const char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putendl_fd(const char *str, int fd)
{
	char	end_line;

	end_line = '\n';
	ft_putstr_fd(str, fd);
	ft_putchar_fd(end_line, fd);
}

void	ft_puterr(const char *str)
{
	ft_putstr_fd(str, 2);
}

int		ft_atoi(const char *src)
{
	int	neg;
	int	value;

	neg = 0;
	value = 0;
	while (*src == ' ' || *src == '\n' || *src == '\v' || *src == '\t'
			|| *src == '\r' || *src == '\f')
		src++;
	if (*src == '+')
		src++;
	else if (*src == '-')
	{
		neg = 1;
		src++;
	}
	while ((*src <= '9') && (*src >= '0'))
	{
		value = (value * 10) - (*src - '0');
		src++;
	}
	if (!neg)
		value = -value;
	return (value);
}