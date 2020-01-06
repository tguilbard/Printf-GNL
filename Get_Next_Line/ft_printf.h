/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:24:57 by tguilbar          #+#    #+#             */
/*   Updated: 2019/11/28 14:27:06 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_list
{
	int	nb_max;
	int	nb_min;
	int	keys;
}				t_list;

int				ft_printf(const char *enter, ...);
int				ft_isdigit(char c);
int				is_charset(char c);
int				ft_atoi(const char *str);
char			*ft_itoa(unsigned int n);
char			*ft_itoa_base(unsigned long int value, char *base);
int				ft_strlen(const char *s);
void			ft_formatchar(t_list info, char c);
void			ft_formatstring(t_list info, char *src);
void			ft_formatadr(t_list info, void *adr, char *base);
void			ft_formatint(t_list info, int n);
void			ft_formatunsint(t_list info, unsigned int n, char *base);
void			z_z(t_list info);

#endif
