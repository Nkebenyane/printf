/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 12:23:10 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/09 10:42:09 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int8_t		ft_printf_o(t_data *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	uintmax_t	org;
	char		*nbr;

	if (**fmt == 'O' && x->len_mod <= 3)
		x->len_mod = 3;
	IF1((ft_init(&x->extra, 1)) == -1, ft_del(ret), -1);
	org = ft_printf_uox_len(x, clone);
	if (org > 0 && x->alt == 1)
		ft_insertn(&x->extra, 0, "0", 1);
	if (x->prec == 0 && x->is_prec == 1 && org == 0 && x->alt == 0)
	{
		handle_width(x, 'o');
		return (ft_printf_append(ret, fmt, x));
	}
	nbr = ft_itoa_base(org, 8, "01234567");
	ft_appendn(&x->extra, nbr, sizeof(char) * ft_strlen(nbr));
	handle_prec(x, org);
	free(nbr);
	handle_width(x, 'o');
	return (ft_printf_append(ret, fmt, x));
}
