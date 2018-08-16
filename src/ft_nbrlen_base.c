/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 07:54:52 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/07 07:55:02 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int8_t		ft_nbrlen_base(uintmax_t src, int8_t base)
{
	int8_t	ret;

	ret = 0;
	if (src == 0)
		return (1);
	while (src != 0)
	{
		src = src / base;
		++ret;
	}
	return (ret);
}
