/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:10:26 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/08 12:10:56 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

uintmax_t	ft_printf_uox_len(t_printf *x, va_list clone)
{
	if (x->len_mod == 0 || x->len_mod == 7)
		return (va_arg(clone, unsigned int));
	if (x->len_mod == 1)
		return ((unsigned char)va_arg(clone, unsigned int));
	if (x->len_mod == 2)
		return ((unsigned short)va_arg(clone, unsigned int));
	if (x->len_mod == 3)
		return (va_arg(clone, unsigned long));
	if (x->len_mod == 4)
		return (va_arg(clone, unsigned long long));
	if (x->len_mod == 5)
		return (va_arg(clone, uintmax_t));
	if (x->len_mod == 6)
		return (va_arg(clone, size_t));
	return (0);
}

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

static void	handle_upper(char *str, char c)
{
	if (c != 'X')
		return ;
	while (*str)
	{
		if (ISALPHA(*str))
			*str = TOUPPER(*str);
		++str;
	}
}

int8_t		ft_printf_x(t_data *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	uintmax_t	org;
	char		*nbr;

	IF1((ft_init(&x->extra, 1)) == -1, ft_del(ret), -1);
	org = ft_printf_uox_len(x, clone);
	if (x->prec == 0 && x->is_prec == 1 && org == 0)
	{
		handle_width(x, 'x');
		return (ft_printf_append(ret, fmt, x));
	}
	nbr = ft_itoa_base(org, 16, "0123456789abcdef");
	ft_appendn(&x->extra, nbr, sizeof(char) * ft_strlen(nbr));
	handle_prec(x, org);
	free(nbr);
	if (x->alt == 1 && org != 0)
		ft_insertn(&x->extra, 0, "0x", 2);
	handle_width(x, 'x');
	handle_upper(x->extra.ptr, **fmt);
	return (ft_printf_append(ret, fmt, x));
}
