/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_confirm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 07:40:42 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/07 09:55:39 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		g_char[ROW][COL] =
{
	{"-"}, {"+"}, {" "}, {"#"}, {"0"}, {"*"}, {"1"}, {"2"},
	{"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"}, {"9"}, {"."},
	{"hh"}, {"h"}, {"ll"}, {"L"}, {"l"}, {"j"}, {"z"}, {"%"},
	{"c"}, {"C"}, {"d"}, {"D"}, {"i"}, {"x"}, {"X"}, {"o"},
	{"O"}, {"u"}, {"U"}, {"s"}, {"S"}, {"p"}, {"e"}, {"E"},
	{"f"}, {"F"}, {"g"}, {"G"}, {"a"}, {"A"}, {"n"}, {"b"}};

static int8_t	(*g_func[ROW]) (t_data *ret, const char **format,
		t_printf *x, va_list list) = {
	ft_flags, ft_flags, ft_flags, ft_flags,
	ft_flags, ft_width, ft_width, ft_width,
	ft_width, ft_width, ft_width, ft_width,
	ft_width, ft_width, ft_width, ft_dot,
	ft_length, ft_length, ft_length, ft_length,
	ft_length, ft_length, ft_length, ft_percent,
	ft_printf_c, ft_printf_c, ft_printf_d, ft_printf_d,
	ft_printf_d, ft_printf_x, ft_printf_x, ft_printf_o,
	ft_printf_o, ft_printf_u, ft_printf_u, ft_printf_s,
	ft_printf_s, ft_printf_p, ft_printf_f, ft_printf_f,
	ft_printf_f, ft_printf_f, ft_printf_f, ft_printf_f,
	ft_printf_f, ft_printf_f, ft_printf_n, ft_printf_b};

static int8_t	search(const char **format, int i)
{
	if (ft_strnstr(*format, g_char[i], COL) != NULL)
		return (1);
	return (0);
}

static int		choose(t_data *ret, const char **format,
		t_printf *x, va_list list)
{
	int i;
	int	len;

	i = -1;
	while (i < ROW && **format)
	{
		i++;
		if ((**format == g_char[i][0]) && ((search(format, i)) == 1))
		{
			IF((len = g_func[i](ret, format, x, list)) == -1, -1);
			if (i < TYPEFIELD)
				i = -1;
			if (len > 0)
				return (len);
		}
	}
	IF(**format == 0, 0);
	IF((ft_init(&x->extra, 5)) == -1, -1);
	ft_appendn(&x->extra, *format, 1);
	handle_width(x, 'c');
	return (ft_printf_append(ret, format, x));
}

int				execute(char **final, const char *format, va_list list)
{
	size_t			i;
	t_data			ret;
	t_printf		x;

	IF((ft_init(&ret, ft_strlen(format) + 20)) == -1, -1);
	IF((ft_printf_init(&x)) == -1, -1);
	IF(*format == 0, 0);
	while (*format)
	{
		i = 0;
		while (format[i] != '%' && format[i] != 0)
			i++;
		ft_appendn(&ret, (char*)format, i);
		format += i;
		if (*format == '%')
		{
			if (*(++format) == 0)
				break ;
			choose(&ret, &format, &x, list);
		}
		IF((ft_printf_init(&x)) == -1, -1);
	}
	*final = ft_tostr(&ret);
	return (ret.len);
}
