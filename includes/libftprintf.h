/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:59:17 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/07 11:33:43 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <wchar.h>
# include "libft.h"
# include "data.h"

# define ROW 49
# define COL 2
# define TYPEFIELD 22

# define IF(a, b) if(1){if(a){return(b);}}
# define IF1(a, b, c) if(1){if(a){b; return(c);}}
# define IF2(a, b, c, d) if(1){if(a){b; c; return(d);}}

# define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
# define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
# define ISSPACE(a) ((a >= 9 && a <= 13) || (a == 32))
# define ISDIGIT(a) (a >= 48 && a <= 57)
# define ISUPPER(a) (a >= 'A' && a <= 'Z')
# define ISLOWER(a) (a >= 'a' && a <= 'z')
# define ISALPHA(a) (ISUPPER(a) || ISLOWER(a))
# define TOLOWER(a) (a >= 'A' && a <= 'Z' ? a + 32 : a)
# define TOUPPER(a) (a >= 'a' && a <= 'z' ? a - 32 : a)

# define ISWIDTH(a) (a > 48 && a <= 57)
# define ISSIGN(a) (a == '+' || a == '-')
# define ISFLAG(a) (a == '+' || a == '-' || a == ' ' || a == '#' || a == '0')
# define ISLENSPEC(a) (a == 'h' || a == 'l' || a == 'j' || a == 'z' || a == 'L')

int				ft_printf(const char *formst, ...);
int				ft_vasprintf(char **ret, const char *format, va_list ap);
int8_t			ft_flags(t_data *r, const char **f, t_printf *x, va_list ap);
int8_t			ft_width(t_data *r, const char **f, t_printf *x, va_list ap);
int8_t			handle_width(t_printf *x, char c);
int8_t			ft_dot(t_data *ret, const char **fmt, t_printf *x, va_list ap);
int8_t			handle_prec(t_printf *x, intmax_t org);
int8_t			ft_length(t_data *r, const char **f, t_printf *x, va_list ap);
int				execute(char **final, const char *fmt, va_list ap);
int8_t			ft_printf_init(t_printf *x);
int8_t			ft_printf_append(t_data *ret, const char **fmt, t_printf *x);
int8_t			ft_printf_c(t_data *ret, const char **fmt, t_printf *x,
		va_list ap);
int8_t			ft_printf_b(t_data *ret, const char **fmt, t_printf *x,
		va_list ap);
int8_t			ft_printf_d(t_data *ret, const char **fmt, t_printf *x,
		va_list ap);
int8_t			ft_percent(t_data *r, const char **f, t_printf *x, va_list ap);
int8_t			ft_printf_p(t_data *ret, const char **fmt, t_printf *x,
		va_list ap);
int8_t			ft_printf_s(t_data *ret, const char **fmt, t_printf *x,
		va_list ap);
int8_t			ft_printf_o(t_data *ret, const char **fmt, t_printf *x,
		va_list ap);
int8_t			ft_printf_u(t_data *ret, const char **fmt, t_printf *x,
		va_list ap);
int8_t			ft_printf_n(t_data *ret, const char **fmt, t_printf *x,
		va_list ap);
int8_t			ft_printf_x(t_data *ret, const char **fmt, t_printf *x,
		va_list ap);
int8_t			ft_printf_f(t_data *ret, const char **fmt, t_printf *x,
		va_list ap);
int8_t			ft_nbrlen_base(uintmax_t src, int8_t base);
char			*ft_itoa_base(uintmax_t n, int8_t base, const char *spec);
int8_t			ft_nbrlen(intmax_t src);
int				ft_wctomb(char *tmp, wchar_t org);

#endif
