/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 17:03:11 by gleger            #+#    #+#             */
/*   Updated: 2014/03/09 13:40:47 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

char		*ft_strdup(const char *s1)
{
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	str = ft_strcpy(str, s1);
	return (str);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}

char		*ft_strcat(char *s1, const char *s2)
{
	ft_strcpy(s1 + ft_strlen(s1), s2);
	return (s1);
}

char		*ft_strcpy(char *str, const char *src)
{
	int			loop;

	loop = -1;
	while (str && src && src[++loop] != '\0')
		str[loop] = src[loop];
	str[loop] = '\0';
	return (str);
}

void		board_error(t_gboard *grid)
{
	if (grid->error != NULL)
	{
		ft_putendl(grid->error);
		grid->error = NULL;
	}
}