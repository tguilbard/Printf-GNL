/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:00:17 by tguilbar          #+#    #+#             */
/*   Updated: 2019/11/29 11:16:35 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*g_dec = "0123456789";
char	*g_hex = "0123456789abcdef";
char	*g_hexm = "0123456789ABCDEF";
int		g_i;

void	ft_transforme(t_list info, va_list lst, char c)
{
	if (c == 'c')
		ft_formatchar(info, va_arg(lst, int));
	if (c == 's')
		ft_formatstring(info, va_arg(lst, char *));
	if (c == 'p')
		ft_formatadr(info, va_arg(lst, void*), g_hex);
	if (c == 'd' || c == 'i')
		ft_formatint(info, va_arg(lst, int));
	if (c == 'u')
		ft_formatunsint(info, va_arg(lst, unsigned int), g_dec);
	if (c == 'x')
		ft_formatunsint(info, va_arg(lst, unsigned int), g_hex);
	if (c == 'X')
		ft_formatunsint(info, va_arg(lst, unsigned int), g_hexm);
	if (c == '%')
		ft_formatchar(info, '%');
}

int		extract_info(int *nb, char *enter, va_list lst, int *keys)
{
	int		i;

	i = 0;
	if (*enter == '*')
	{
		*nb = va_arg(lst, int);
		*keys = (*nb < 0) ? -1 : *keys;
		*nb = (*nb < 0) ? -*nb : *nb;
		return (1);
	}
	*nb = ft_atoi(enter);
	while (ft_isdigit(enter[i]))
		i++;
	return (i);
}

int		ft_parsing2(t_list info, va_list lst, int i, char *enter)
{
	if ((enter[i] >= '1' && enter[i] <= '9') || enter[i] == '*')
		i += extract_info(&info.nb_min, enter + i, lst, &info.keys);
	if (enter[i] == '.')
		i += extract_info(&info.nb_max, enter + i + 1, lst, &info.keys) + 1;
	ft_transforme(info, lst, enter[i]);
	return (i + 1);
}

int		ft_parsing(char *enter, va_list lst)
{
	int		i;
	t_list	info;

	i = 1;
	info.keys = 0;
	info.nb_max = -1;
	info.nb_min = 0;
	if (enter[i] == '0')
	{
		info.keys = 1;
		while (enter[i + 1] == '0')
			i++;
		i += extract_info(&info.nb_min, enter + i + 1, lst, &info.keys) + 1;
	}
	if (enter[i] == '-')
	{
		info.keys = -1;
		while (enter[i + 1] == '-')
			i++;
		i += extract_info(&info.nb_min, enter + i + 1, lst, &info.keys) + 1;
	}
	return (ft_parsing2(info, lst, i, enter));
}

int		ft_printf(const char *enter, ...)
{
	va_list lst;
	int		i;

	g_i = 0;
	i = 0;
	va_start(lst, enter);
	while (enter[i])
	{
		if (enter[i] == '%')
			i += ft_parsing((char*)(enter + i), lst);
		else
			g_i += write(1, enter + i++, 1);
	}
	va_end(lst);
	return (g_i);
}
