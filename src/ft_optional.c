/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optional.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 07:55:21 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/07 16:35:04 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int8_t	ft_flags(t_data *ret, const char **format,
		t_printf *x, va_list ap)
{
	(void)ret;
	(void)ap;
	while (*format && ISFLAG(**format))
	{
		if (**format == '-')
			x->left = 1;
		else if (**format == '+')
			x->showsign = 1;
		else if (**format == ' ')
			x->space = 1;
		else if (**format == '#')
			x->alt = 1;
		else if (**format == '0')
			x->zero = 1;
		++*format;
		++x->extra.len;
	}
	x->zero = (x->left == 0) ? x->zero : 0;
	x->space = (x->showsign == 0) ? x->space : 0;
	x->pad = (x->zero) ? '0' : ' ';
	return (0);
}

int8_t	ft_width(t_data *ret, const char **format,
		t_printf *x, va_list ap)
{
	size_t	res;

	res = 0;
	if (**format == '0')
		return (ft_flags(ret, format, x, ap));
	while (ISDIGIT(**format))
	{
		res = res * 10 + (**format - '0');
		++*format;
	}
	x->width = res;
	while (**format == '*')
	{
		x->width = va_arg(ap, int);
		++*format;
	}
	if (x->width < 0)
	{
		x->width = -x->width;
		x->left = 1;
	}
	return (0);
}

int8_t	ft_dot(t_data *ret, const char **format, t_printf *x, va_list ap)
{
	int res;

	(void)ret;
	(void)ap;
	res = 0;
	++*format;
	if (**format == '*')
	{
		res = va_arg(ap, int);
		++*format;
	}
	else
	{
		while (ISDIGIT(**format))
		{
			res = res * 10 + (**format - '0');
			++*format;
		}
	}
	x->prec = (res < 0) ? 0 : res;
	x->is_prec = (res < 0) ? 0 : 1;
	return (0);
}

int8_t	ft_length(t_data *ret, const char **format,
		t_printf *x, va_list ap)
{
	int		index;
	char	*legnth_spec;

	legnth_spec = "hhlljzL";
	(void)ret;
	(void)ap;
	while (ISLENSPEC(**format))
	{
		index = ft_strchr(legnth_spec, **format) - legnth_spec + 1;
		if (index == 1)
		{
			if (*(*format + 1) == 'h')
				++*format;
			else
				index = 2;
		}
		if (index == 3)
		{
			index = ((*(*format + 1)) == 'l') ? index + 1 : index;
		}
		x->len_mod = (index > x->len_mod) ? index : x->len_mod;
		++*format;
	}
	return (0);
}
