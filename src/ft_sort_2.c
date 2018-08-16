/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:13:22 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/07 16:35:51 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int8_t	ft_append_arr(t_data *dst, t_data *src)
{
	IF(dst == 0, -1);
	IF(dst->cap == 0, -1);
	IF(ft_sizechk(dst, src->len) == -1, -1);
	ft_memcpy(&dst->ptr[dst->len], src->ptr, src->len);
	dst->len += src->len;
	return (0);
}

void	ft_del(t_data *src)
{
	if (src == 0)
		return ;
	if (src->cap > 0)
		free(src->ptr);
	ft_bzero(src, sizeof(t_data));
}

int8_t	ft_printf_append(t_data *ret, const char **fmt, t_printf *x)
{
	IF2((ft_append_arr(ret, &x->extra)) == -1,
			ft_del(ret), ft_del(&x->extra), -1);
	ft_del(&x->extra);
	++*fmt;
	return (ret->len);
}

int8_t	ft_printf_init(t_printf *x)
{
	ft_bzero(x, sizeof(t_printf));
	x->pad = ' ';
	return (0);
}

char	*ft_tostr(t_data *src)
{
	IF(src == 0, 0);
	IF(src->cap == 0, 0);
	if (src->len != src->cap)
		if (src->ptr[src->len] == 0)
			return (src->ptr);
	IF(ft_appendn(src, "", 1) == -1, 0);
	--src->len;
	return (src->ptr);
}
