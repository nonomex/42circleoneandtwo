/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:54:47 by aammirat          #+#    #+#             */
/*   Updated: 2023/01/09 09:54:51 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# if BUFFER_SIZE < 1
#  define BUFFER_SIZE 1
# endif
# if BUFFER_SIZE > 2147483647
#  define BUFFER_SIZE 2147483647
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1064
# endif

int		isline(char *str);
char	*get_next_line(int fd);
char	*join(char *x, char *y);
void	suprline(char *str, int all);
char	*nextline(char *str, size_t i, int fd, int a);
char	*findnext(char *new, char *str, int fd, int a);

#endif