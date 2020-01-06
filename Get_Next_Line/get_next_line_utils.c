/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:31:24 by tguilbar          #+#    #+#             */
/*   Updated: 2019/11/20 20:31:29 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	strlen2(char *s1, char *s2, int type)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1)
		while (s1[i] && (type == 0 || (type == 1 && s1[i] != '\n')))
			i++;
	if (type == 0)
	{
		while (s2[j])
			j++;
		return (i + j);
	}
	if (!s1)
		return (1);
	else if (s1[i] != '\n')
		return (1);
	return (0);
}
