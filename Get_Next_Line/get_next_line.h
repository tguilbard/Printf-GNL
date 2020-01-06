/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:37:29 by tguilbar          #+#    #+#             */
/*   Updated: 2019/12/13 11:21:51 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);
unsigned int	strlen2(char *s1, char *s2, int type);

#endif
