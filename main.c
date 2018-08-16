/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 10:24:54 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/10 10:18:47 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int main(void)
{
	char a[] = "hello";

	ft_printf("%%\n");
	ft_printf("%s\n", "hello");
	ft_printf("%i %c %i %c\n", 12, 'b', 14, 'c');

	ft_printf("%#x\n", 16);
	ft_printf("%03i\n", 1);
	ft_printf("%-+i\n", 2);

	ft_printf("%.3i\n", 3);
//	printf("%.3f", 3);





}
