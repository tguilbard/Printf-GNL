/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:37:29 by tguilbar          #+#    #+#             */
/*   Updated: 2019/12/13 11:21:42 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_list
{
	int				ret;
	int				fd;
	char			*stock;
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
unsigned int	strlen2(char *s1, char *s2, int type);
int				check_create(int fd, t_list **lst);
t_list			*fb(int fd, t_list **lst);
void			rm_lst(int fd, t_list **lst);

#endif
