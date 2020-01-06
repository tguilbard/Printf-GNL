/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:16:31 by tguilbar          #+#    #+#             */
/*   Updated: 2019/11/28 17:23:32 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_charset(char c)
{
	if (c == 'c' || c == '%' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int	s;
	int	stk;

	stk = 0;
	s = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\v' ||
		*str == '\t' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		s = -1;
	while (*str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		stk *= 10;
		stk += *str - '0';
		str++;
	}
	return (stk * s);
}

int		ft_isdigit(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

char	*ft_itoa(unsigned int n)
{
	unsigned int	count;
	unsigned int	tmp;
	char			*res;

	count = (n < 0) ? 2 : 1;
	tmp = (n < 0) ? -n : n;
	while (tmp >= 10 && (tmp /= 10))
		++count;
	tmp = (n < 0) ? -n : n;
	if (!(res = malloc(count + 1)))
		return (NULL);
	if (n < 0)
		res[0] = '-';
	res[count] = '\0';
	while (tmp >= 10)
	{
		--count;
		res[count] = (tmp % 10) + '0';
		tmp /= 10;
	}
	res[--count] = (tmp % 10) + '0';
	return (res);
}

char	*ft_itoa_base(unsigned long int value, char *base)
{
	int					count;
	unsigned long int	tmp;
	char				*res;
	unsigned long int	base_length;

	base_length = ft_strlen(base);
	count = (value < 0) ? 2 : 1;
	tmp = (value < 0) ? -value : value;
	while (tmp >= base_length && (tmp /= base_length))
		++count;
	tmp = (value < 0) ? -value : value;
	if (!(res = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	if (value < 0)
		res[0] = '-';
	res[count] = '\0';
	while (tmp >= base_length)
	{
		--count;
		res[count] = base[tmp % base_length];
		tmp /= base_length;
	}
	res[--count] = base[tmp % base_length];
	return (res);
}
