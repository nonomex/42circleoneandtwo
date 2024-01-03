/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:54:57 by aammirat          #+#    #+#             */
/*   Updated: 2023/05/09 16:44:35 by aammirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE][OPEN_MAX];
	char		*new;
	int			a;
	size_t		i;

	i = 0;
	a = 1;
	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (!str[0])
		a = read(fd, str[fd], BUFFER_SIZE);
	if (a == 0 || a == -1)
	{
		suprline(str[fd], 0);
		return (NULL);
	}
	while (str[fd][i] && str[fd][i] != '\n')
		i++;
	new = nextline(str[fd], i, fd, a);
	suprline(str[fd], 0);
	return (new);
}
