/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:59:08 by tguilbar          #+#    #+#             */
/*   Updated: 2019/11/28 12:23:13 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_i;

void	ft_formatstring2(t_list info, char *src, char *str, size_t size)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (info.keys == 0)
		while (i + info.nb_max < size)
			str[i++] = ' ';
	while (j < info.nb_max)
		str[i++] = src[j++];
	if (info.keys == -1)
		while (i < size)
			str[i++] = ' ';
	str[i] = '\0';
}

void	ft_formatstring(t_list info, char *src)
{
	char	*str;
	size_t	size;

	if (src == NULL)
		src = "(null)";
	size = ft_strlen(src);
	if (info.nb_max > 0)
		info.nb_max = ((int)size < info.nb_max) ? size : info.nb_max;
	else
		info.nb_max = ft_strlen(src);
	size = (info.nb_min > info.nb_max) ? info.nb_min : info.nb_max;
	if (!(str = malloc(size + 1)))
		return ;
	ft_formatstring2(info, src, str, size);
	g_i = write(1, str, ft_strlen(str));
	free(str);
}
