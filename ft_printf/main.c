/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:48:52 by tguilbar          #+#    #+#             */
/*   Updated: 2019/12/02 13:55:32 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

#define TEST "'%-d'\n", 12

int main()
{
	int i;
	int j;

	i = ft_printf(TEST);
	j = printf(TEST);
	printf("%d | %d", i, j);
	system("leaks a.out | grep 'leaked'");
}
