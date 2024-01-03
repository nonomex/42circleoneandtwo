/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:55:04 by aammirat          #+#    #+#             */
/*   Updated: 2023/05/09 16:44:50 by aammirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*join(char *x, char *y)
{
	char	*new;
	int		i;
	int		j;

	if (!x || !y)
		return (NULL);
	i = 0;
	j = 0;
	while (x[i])
		i++;
	while (y[j])
		j++;
	new = malloc ((i + j + 1) * sizeof(char) + 1);
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	while (x[++i])
		new[i] = x[i];
	while (y[++j])
		new[i + j] = y[j];
	new[i + j] = '\0';
	free (x);
	return (new);
}

char	*findnext(char *new, char *str, int fd, int a)
{
	int		i;
	char	*buff;

	i = -1;
	while (str[++i] != '\n' && a != 0)
	{
		if (!str[i])
		{
			new = join(new, str);
			if (!new)
				return (new);
			suprline(str, 1);
			a = read(fd, str, BUFFER_SIZE);
			i = -1;
		}
	}
	if (a != 0)
	{
		buff = nextline(str, i, fd, a);
		new = join(new, buff);
		if (buff)
			free(buff);
		return (new);
	}
	return (new);
}

int	isline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*nextline(char *str, size_t i, int fd, int a)
{
	char	*new;
	size_t	j;
	int		bol;
	char	*ret;

	j = -1;
	ret = NULL;
	new = malloc ((i + 1) * sizeof(char) + 1);
	if (!new)
		return (NULL);
	while (++j <= i)
		new[j] = str[j];
	new[j] = '\0';
	bol = isline(new);
	if (bol == 1)
		return (new);
	suprline(str, 1);
	a = read(fd, str, BUFFER_SIZE);
	if (a >= 0)
		ret = findnext(new, str, fd, a);
	else
		free (new);
	return (ret);
}

void	suprline(char *str, int all)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (all == 0)
	{
		i = 0;
		while (str[i] && str[i - 1] != '\n')
			i++;
		while (str[i + j])
		{
			str[j] = str[i + j];
			j++;
		}
	}
	while (j < BUFFER_SIZE)
	{
		str[j] = '\0';
		j++;
	}
}
