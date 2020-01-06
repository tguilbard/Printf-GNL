/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:35:26 by tguilbar          #+#    #+#             */
/*   Updated: 2019/11/28 12:54:40 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_i;

void	ft_formatchar(t_list info, char c)
{
	char	*str;
	int		i;

	i = 0;
	info.nb_min = (info.nb_min > 1) ? info.nb_min : 1;
	if (!(str = malloc((size_t)info.nb_min + 1)))
		return ;
	if (info.keys == 0)
		while (i + 1 < info.nb_min)
			str[i++] = ' ';
	if (info.keys == 1)
		while (i + 1 < info.nb_min)
			str[i++] = '0';
	str[i++] = c;
	if (info.keys == -1)
		while (i < info.nb_min)
			str[i++] = ' ';
	str[i] = '\0';
	i = (ft_strlen(str) == 0) ? 1 : ft_strlen(str);
	g_i += write(1, str, i);
	free(str);
}
