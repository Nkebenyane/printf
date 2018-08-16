/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:05:52 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/07 17:17:41 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

intmax_t	ft_printf_d_len(t_printf *x, va_list clone)
{
	if (x->len_mod == 0 || x->len_mod == 7)
		return (va_arg(clone, int));
	if (x->len_mod == 1)
		return ((signed char)va_arg(clone, int));
	if (x->len_mod == 2)
		return ((short)va_arg(clone, int));
	if (x->len_mod == 3)
		return (va_arg(clone, long));
	if (x->len_mod == 4)
		return (va_arg(clone, long long));
	if (x->len_mod == 5)
		return (va_arg(clone, intmax_t));
	if (x->len_mod == 6)
		return (va_arg(clone, ssize_t));
	return (0);
}

int8_t		ft_printf_d(t_data *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	intmax_t	org;
	char		*nbr;

	x->len_mod = (**fmt == 'D' && x->len_mod <= 3) ? 3 : x->len_mod;
	if (x->is_prec == 1)
		x->zero = 0;
	IF1((ft_init(&x->extra, 100)) == -1, ft_del(ret), -1);
	org = ft_printf_d_len(x, clone);
	if (x->prec == 0 && x->is_prec == 1 && org == 0)
	{
		if (org >= 0 && x->showsign == 1)
			ft_insertn(&x->extra, 0, "+", 1);
		handle_width(x, 'd');
		return (ft_printf_append(ret, fmt, x));
	}
	nbr = ft_itoa(org);
	ft_appendn(&x->extra, nbr, sizeof(char) * ft_strlen(nbr));
	handle_prec(x, org);
	if (org >= 0 && x->showsign == 1)
		ft_insertn(&x->extra, 0, "+", 1);
	if (org >= 0 && x->space == 1 && x->width == 0)
		ft_insertn(&x->extra, 0, " ", 1);
	free(nbr);
	handle_width(x, 'd');
	return (ft_printf_append(ret, fmt, x));
}
