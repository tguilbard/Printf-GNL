/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatunsint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:04:50 by tguilbar          #+#    #+#             */
/*   Updated: 2019/11/28 13:56:25 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_i;

void	ft_formatunsint2(t_list info, char *str, char *nb, char c)
{
	int i;
	int j;

	i = 0;
	if (info.keys == 0)
		while (i + info.nb_max < info.nb_min)
			str[i++] = ' ';
	if (info.keys == 1)
		while (i + info.nb_max < info.nb_min)
			str[i++] = c;
	j = 0;
	while (j++ < info.nb_max - (int)ft_strlen(nb))
		str[i++] = '0';
	j = 0;
	while (j < ft_strlen(nb))
		str[i++] = nb[j++];
	if (info.keys == -1)
		while (i < info.nb_min)
			str[i++] = ' ';
	str[i] = '\0';
}

void	ft_formatunsint(t_list info, unsigned int n, char *base)
{
	char	*nb;
	char	*str;
	char	c;

	if (n == 0 && info.nb_max == 0)
		return (z_z(info));
	nb = ft_itoa_base(n, base);
	c = (info.nb_max == -1) ? '0' : ' ';
	info.nb_max = (info.nb_max > ft_strlen(nb)) ? info.nb_max : ft_strlen(nb);
	info.nb_min = (info.nb_min > info.nb_max) ? info.nb_min : info.nb_max;
	if (!(str = malloc((size_t)info.nb_min + 1)))
		return ;
	ft_formatunsint2(info, str, nb, c);
	free(nb);
	g_i += write(1, str, ft_strlen(str));
	free(str);
}
