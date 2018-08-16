/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:11:53 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/07 08:12:25 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	set_index(t_printf *x, char c)
{
	size_t	index;

	index = 0;
	index = (x->left == 1) ? x->extra.len : 0;
	index = (x->pad == '0' && ISSIGN(x->extra.ptr[index])) ? index + 1 : index;
	if ((c == 'x' || c == 'p') && x->left == 0)
	{
		if (x->pad == ' ')
			index = (ft_strstr(x->extra.ptr, "0x") != NULL) ? 0 : index;
		else
			index = (ft_strstr(x->extra.ptr, "0x") != NULL) ? 2 : 0;
	}
	if (c == 'b' && x->pad != ' ')
		index = (ft_strstr(x->extra.ptr, "0b") != NULL) ? 2 : index;
	return (index);
}

int8_t	handle_width(t_printf *x, char c)
{
	char	*tmp;
	int		diff;
	size_t	index;

	if (x->is_prec == 1 && c != 'c' && c != 's' && c != '%')
		x->pad = ' ';
	diff = x->width - x->extra.len;
	index = set_index(x, c);
	if (x->space == 1 && x->zero == 1 && diff > 0)
	{
		ft_insertn(&x->extra, 0, " ", 1);
		++index;
		--diff;
	}
	if (diff > 0)
	{
		IF((tmp = ft_strnew(diff)) == 0, -1);
		ft_memset((void *)tmp, (int)x->pad, (size_t)diff);
		ft_insertn(&x->extra, index, tmp, diff);
		free(tmp);
	}
	if (x->space == 1 && (x->width < x->prec) && !ft_strchr(x->extra.ptr, ' '))
		ft_insertn(&x->extra, 0, " ", 1);
	return (0);
}

int8_t	handle_prec(t_printf *x, intmax_t org)
{
	char	*tmp;
	int		diff;
	int		index;

	if (x->is_prec == 0 && x->prec == 0)
		return (0);
	if (x->prec < (int)x->extra.len)
		return (0);
	diff = (org >= 0) ? x->prec - x->extra.len : x->prec - x->extra.len + 1;
	index = (org >= 0) ? 0 : 1;
	if (diff > 0)
	{
		IF((tmp = ft_strnew(diff)) == 0, 0);
		ft_memset(tmp, '0', diff);
		ft_insertn(&x->extra, index, tmp, diff);
	}
	return (0);
}
