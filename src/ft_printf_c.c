/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:52:12 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/07 09:45:40 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int8_t		ft_percent(t_data *ret, const char **fmt,
		t_printf *x, va_list list)
{
	(void)list;
	IF1((ft_init(&x->extra, 1)) == -1, ft_del(ret), -1);
	ft_insertn(&x->extra, 0, "%", 1);
	handle_width(x, '%');
	return (ft_printf_append(ret, fmt, x));
}

int8_t		ft_printf_wchar(t_data *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	int		len;
	char	tmp[5];
	wchar_t	org;

	org = (wchar_t)va_arg(clone, wint_t);
	len = ft_wctomb(tmp, org);
	ft_appendn(&x->extra, tmp, sizeof(char) * len);
	handle_width(x, 'c');
	return (ft_printf_append(ret, fmt, x));
}

int8_t		ft_printf_c(t_data *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	unsigned char	tmp[1];

	if (**fmt == 'C')
		x->len_mod = 3;
	IF1((ft_init(&x->extra, 5)) == -1, ft_del(ret), -1);
	if (x->len_mod == 3)
		return (ft_printf_wchar(ret, fmt, x, clone));
	tmp[0] = (unsigned char)va_arg(clone, int);
	ft_appendn(&x->extra, tmp, 1);
	handle_width(x, 'c');
	return (ft_printf_append(ret, fmt, x));
}
