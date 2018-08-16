/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:02:20 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/07 08:02:58 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int8_t		ft_printf_b(t_data *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	uintmax_t	org;
	char		*nbr;

	IF1((ft_init(&x->extra, 1)) == -1, ft_del(ret), -1);
	org = ft_printf_uox_len(x, clone);
	if (x->prec == 0 && x->is_prec == 1 && org == 0)
	{
		handle_width(x, 'b');
		return (ft_printf_append(ret, fmt, x));
	}
	nbr = ft_itoa_base(org, 2, "012");
	ft_appendn(&x->extra, nbr, sizeof(char) * ft_strlen(nbr));
	free(nbr);
	if (x->alt == 1 && org != 0)
		ft_insertn(&x->extra, 0, "0b", 2);
	handle_width(x, 'b');
	return (ft_printf_append(ret, fmt, x));
}
