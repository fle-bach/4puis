/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 11:29:34 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/17 11:38:21 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char		**ft_malloc_cut(char **cut, int count, int *start, char *line)
{
	char			*tmp;
	static int		i = 0;

	tmp = ft_strsub(line, *start, (count - *start));
	tmp = ft_strtrim(tmp);
	if (ft_strcmp(tmp, ""))
	{
		cut = ft_realloc(cut, tmp, i);
		i++;
	}
	*start = count;
	free(tmp);
	if (!(line[count]))
		i = 0;
	return (cut);
}

char			**ft_cut(t_sh sh)
{
	char	**cut;
	int		count;
	int		start;

	count = 0;
	start = count;
	while (sh.line[count])
	{
		if (sh.line[count] == '<' || sh.line[count] == '>'
				|| sh.line[count] == '|')
		{
			cut = ft_malloc_cut(cut, count, &start, sh.line);
			while (sh.line[count] == '<' || sh.line[count] == '>'
					|| sh.line[count] == '|')
				count++;
			cut = ft_malloc_cut(cut, count, &start, sh.line);
		}
		if (sh.line[count])
			count++;
	}
	cut = ft_malloc_cut(cut, count, &start, sh.line);
	return (cut);
}
