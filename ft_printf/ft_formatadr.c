/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatadr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:21:33 by tguilbar          #+#    #+#             */
/*   Updated: 2019/11/28 13:57:19 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_i;

void	ft_formatadr(t_list info, void *adr, char *base)
{
	char		*nb;
	char		*str;
	size_t		size;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	nb = ft_itoa_base((unsigned long int)adr, base);
	size = (ft_strlen(nb) + 2 < info.nb_min) ? info.nb_min : ft_strlen(nb) + 2;
	if (!(str = malloc(size + 1)))
		return ;
	if (info.keys == 0)
		while (i + ft_strlen(nb) + 2 < size)
			str[i++] = ' ';
	str[i++] = '0';
	str[i++] = 'x';
	while (nb[j])
		str[i++] = nb[j++];
	if (info.keys == -1)
		while (i < size)
			str[i++] = ' ';
	free(nb);
	g_i += write(1, str, i);
	free(str);
}
