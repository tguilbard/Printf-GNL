/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_z.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:05:38 by tguilbar          #+#    #+#             */
/*   Updated: 2019/11/29 10:38:06 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_i;

void	z_z(t_list info)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc((size_t)info.nb_min + 1)))
		return ;
	if (info.keys == 0)
		while (i < info.nb_min)
			str[i++] = ' ';
	if (info.keys == 1)
		while (i < info.nb_min)
			str[i++] = ' ';
	str[i] = '\0';
	if (info.keys == -1)
		while (i < info.nb_min)
			str[i++] = ' ';
	str[i] = '\0';
	g_i += write(1, str, ft_strlen(str));
	free(str);
}
