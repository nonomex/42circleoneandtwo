/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:54:57 by aammirat          #+#    #+#             */
/*   Updated: 2023/01/09 09:54:58 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE];
	char		*new;
	int			a;
	size_t		i;

	i = 0;
	a = 1;
	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (!str[0])
		a = read(fd, str, BUFFER_SIZE);
	if (a == 0 || a == -1)
	{
		suprline(str, 0);
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	new = nextline(str, i, fd, a);
	suprline(str, 0);
	return (new);
}
