/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:12:49 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/07 14:41:58 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int8_t	ft_init(t_data *src, size_t size)
{
	if (src == 0 || size == 0)
		return (-1);
	ft_bzero(src, sizeof(t_data));
	IF((src->ptr = ft_memalloc(size)) == NULL, -1);
	src->cap = size;
	src->len = 0;
	return (0);
}

int8_t	ft_sizechk(t_data *src, size_t size)
{
	IF(src == 0, -1);
	IF(src->cap == 0, -1);
	if (size + src->len > src->cap)
		IF(ft_resize(src, size) == -1, -1);
	return (0);
}

int8_t	ft_resize(t_data *src, size_t size)
{
	size_t	malloc_size;
	void	*tmp;

	malloc_size = src->cap;
	IF(src == 0, -1);
	IF(src->cap == 0, -1);
	if (size + src->len > malloc_size)
	{
		while (size + src->len > malloc_size)
			malloc_size *= 2;
		IF((tmp = ft_memalloc(malloc_size)) == 0, -1);
		if (src->len != 0)
			ft_memcpy(tmp, src->ptr, src->len);
		free(src->ptr);
		src->ptr = tmp;
		src->cap = malloc_size;
	}
	return (0);
}

int8_t	ft_insertn(t_data *dst, size_t index,
		const void *src, size_t src_len)
{
	IF(dst == 0, -1);
	IF(dst->cap == 0, -1);
	IF((ft_sizechk(dst, src_len) == -1), -1);
	if (index < dst->len)
		ft_memmove(&dst->ptr[index + src_len],
				&dst->ptr[index], dst->len - index);
	ft_memcpy(&dst->ptr[index], src, src_len);
	dst->len += src_len;
	return (0);
}

int8_t	ft_appendn(t_data *dst, const void *src, size_t n)
{
	IF(dst == 0, -1);
	IF(dst->cap == 0, -1);
	IF(ft_sizechk(dst, n) == -1, -1);
	ft_memcpy(&dst->ptr[dst->len], src, n);
	dst->len += n;
	return (0);
}
