/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:34:50 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/08 12:33:29 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct		s_data
{
	char			*ptr;
	size_t			len;
	size_t			cap;
}					t_data;

typedef struct		s_printf
{
	unsigned int	is_prec:1;
	int				prec;
	int				width;
	unsigned int	left:1;
	unsigned int	showsign:1;
	unsigned int	space:1;
	unsigned int	zero:1;
	unsigned int	alt:1;
	uint8_t			len_mod;
	char			pad;
	t_data			extra;
}					t_printf;

void				ft_del(t_data *src);
char				*ft_tostr(t_data *src);
int8_t				ft_init(t_data *src, size_t cap);
int8_t				ft_appendn(t_data *dst, const void *src, size_t n);
int8_t				ft_resize(t_data *src, size_t size);
int8_t				ft_sizechk(t_data *src, size_t size);
int8_t				ft_insertn(t_data *dst, size_t index,
		const void *src, size_t src_len);
uintmax_t			ft_printf_uox_len(t_printf *x, va_list list);

#endif
