/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:06:06 by tguilbar          #+#    #+#             */
/*   Updated: 2019/11/28 21:17:00 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

extern int g_i;

int		ft_formatint2(t_list info, char *str, char *nb, char c[2])
{
	int i;
	int j;

	i = 0;
	j = (c[1] == '-') ? 1 : 0;
	if (info.keys == 0)
		while (i + info.nb_max + j < info.nb_min)
			str[i++] = ' ';
	if (c[1] == '-' && c[0] != ' ')
		str[i++] = c[1];
	else if (c[1] == '-')
		info.nb_min -= 1;
	if (info.keys == 1)
		while (i + info.nb_max < info.nb_min)
			str[i++] = c[0];
	if (c[1] == '-' && c[0] == ' ')
		str[i++] = c[1];
	j = 0;
	while (j++ < info.nb_max - (int)ft_strlen(nb))
		str[i++] = '0';
	j = 0;
	while (j < (int)ft_strlen(nb))
		str[i++] = nb[j++];
	return (i);
}

void	ft_formatint(t_list info, int n)
{
	int		i;
	char	*nb;
	char	*str;
	char	c[2];

	if (n == 0 && info.nb_max == 0)
		return (z_z(info));
	c[1] = (n < 0) ? '-' : '+';
	n = (n < 0) ? (unsigned int)-n : n;
	nb = ft_itoa(n);
	c[0] = (info.nb_max == -1) ? '0' : ' ';
	info.nb_max = (info.nb_max > ft_strlen(nb)) ? info.nb_max : ft_strlen(nb);
	info.nb_min = (info.nb_min > info.nb_max) ? info.nb_min : info.nb_max;
	if (!(str = malloc((size_t)info.nb_min + 1)))
		return ;
	i = ft_formatint2(info, str, nb, c);
	if (info.keys == -1)
		while (i < info.nb_min)
			str[i++] = ' ';
	str[i] = '\0';
	free(nb);
	g_i += write(1, str, ft_strlen(str));
	free(str);
}
