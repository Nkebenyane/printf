/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 12:07:35 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/09 10:42:19 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int8_t		ft_printf_u(t_data *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	uintmax_t	org;
	char		*nbr;

	if (**fmt == 'U' && x->len_mod <= 3)
		x->len_mod = 3;
	IF1((ft_init(&x->extra, 1)) == -1, ft_del(ret), -1);
	org = ft_printf_uox_len(x, clone);
	if (x->prec == 0 && x->is_prec == 1 && org == 0 && x->alt == 0)
	{
		handle_width(x, 'u');
		return (ft_printf_append(ret, fmt, x));
	}
	nbr = ft_itoa_base(org, 10, "0123456789");
	ft_appendn(&x->extra, nbr, sizeof(char) * ft_strlen(nbr));
	handle_prec(x, org);
	free(nbr);
	handle_width(x, 'u');
	return (ft_printf_append(ret, fmt, x));
}
