/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:09:28 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/07 17:24:30 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

intmax_t	*ft_printf_n_len(t_printf *x, va_list clone)
{
	if (x->len_mod == 0 || x->len_mod == 7)
		return ((intmax_t *)va_arg(clone, int *));
	if (x->len_mod == 1)
		return ((intmax_t *)va_arg(clone, signed char *));
	if (x->len_mod == 2)
		return ((intmax_t *)va_arg(clone, short *));
	if (x->len_mod == 3)
		return ((intmax_t *)va_arg(clone, long *));
	if (x->len_mod == 4)
		return ((intmax_t *)va_arg(clone, long long *));
	if (x->len_mod == 5)
		return ((intmax_t *)va_arg(clone, intmax_t *));
	if (x->len_mod == 6)
		return ((intmax_t *)va_arg(clone, ssize_t *));
	return (0);
}

int8_t		ft_printf_n(t_data *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	intmax_t	*i;
	int			tmp;

	tmp = ret->len;
	i = ft_printf_n_len(x, clone);
	*i = (intmax_t)tmp;
	++*fmt;
	return (0);
}
