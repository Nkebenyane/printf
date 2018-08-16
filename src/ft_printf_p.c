/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:54:56 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/07 17:17:05 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int8_t	ft_printf_p(t_data *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	uintmax_t	org;
	char		*nbr;

	IF1((ft_init(&x->extra, 5)) == -1, ft_del(ret), -1);
	org = (uintmax_t)va_arg(clone, void*);
	if (x->prec == 0 && x->is_prec == 1 && org == 0)
	{
		ft_insertn(&x->extra, 0, "0x", 2);
		handle_width(x, 'p');
		return (ft_printf_append(ret, fmt, x));
	}
	nbr = (org != 0) ? ft_itoa_base(org, 16, "0123456789abcdef")
		: ft_strdup("0");
	ft_appendn(&x->extra, nbr, sizeof(char) * ft_strlen(nbr));
	handle_prec(x, org);
	ft_insertn(&x->extra, 0, "0x", 2);
	free(nbr);
	handle_width(x, 'p');
	return (ft_printf_append(ret, fmt, x));
}
