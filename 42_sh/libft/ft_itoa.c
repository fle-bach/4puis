/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:54:56 by fle-bach          #+#    #+#             */
/*   Updated: 2013/12/16 17:54:57 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_numdig(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_fillstr(char *str, int n, size_t pos, int sign)
{
	str[pos] = '\0';
	pos--;
	if (n == 0)
		str[pos] = '0';
	while (n > 0)
	{
		str[pos] = (n % 10) + '0';
		n = n / 10;
		pos--;
	}
	if (sign < 0)
		str[pos] = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = n;
	if (sign < 0)
		n = -n;
	len = ((sign < 0) ? 1 : 0) + ft_numdig(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str)
		ft_fillstr(str, n, len, sign);
	return (str);
}
