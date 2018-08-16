/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:57:29 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/07 09:02:46 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t		ft_wcslen(wchar_t *wstr)
{
	size_t	len;
	wchar_t	*p;

	if (wstr == NULL)
		return (6);
	p = wstr;
	while (*p != 0)
		p++;
	len = (char *)p - (char *)wstr;
	return (len);
}

int8_t		ft_printf_wstr(t_data *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	wchar_t	*tmp;
	char	*final;
	int		len;
	int		i;
	int		k;

	tmp = va_arg(clone, wchar_t*);
	if (x->is_prec == 1)
		len = MIN(x->prec, (int)ft_wcslen(tmp));
	else
		len = ft_wcslen(tmp);
	final = (tmp != NULL) ? ft_strnew(len) : ft_strdup("(null)");
	i = (tmp != NULL) ? 0 : len;
	while (tmp && *tmp != 0)
	{
		k = ft_wctomb(&final[i], *tmp);
		if (k + i > len)
			break ;
		i += k;
		++tmp;
	}
	ft_appendn(&x->extra, final, sizeof(char) * i);
	free(final);
	handle_width(x, 's');
	return (ft_printf_append(ret, fmt, x));
}

int8_t		ft_printf_s(t_data *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	char	*tmp;
	char	*final;
	int		n;

	IF1((ft_init(&x->extra, 5)) == -1, ft_del(ret), -1);
	if (**fmt == 'S' || x->len_mod == 3)
		return (ft_printf_wstr(ret, fmt, x, clone));
	tmp = va_arg(clone, char*);
	final = (tmp != NULL) ? ft_strdup(tmp) : ft_strdup("(null)");
	if (x->is_prec == 1)
		n = MIN(x->prec, (int)ft_strlen(final));
	else
		n = ft_strlen(final);
	ft_appendn(&x->extra, final, sizeof(char) * n);
	free(final);
	handle_width(x, 's');
	return (ft_printf_append(ret, fmt, x));
}
