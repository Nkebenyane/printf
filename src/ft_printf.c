/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:30:59 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/09 10:40:57 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*ret;
	int		len;

	if (format == 0 || *format == 0)
		return (0);
	va_start(ap, format);
	IF((len = ft_vasprintf(&ret, format, ap)) == -1, -1);
	write(1, ret, len);
	free(ret);
	va_end(ap);
	return (len);
}

int		ft_vasprintf(char **ret, const char *format, va_list ap)
{
	int		len;
	va_list	list;

	if (*format == 0)
		*ret = ft_strnew(0);
	if (format == 0 || *format == 0 || ret == 0)
		return (0);
	*ret = 0;
	if (ft_strchr(format, '%') == NULL)
	{
		*ret = ft_strdup(format);
		return (ft_strlen(format));
	}
	va_copy(list, ap);
	len = execute(ret, format, list);
	va_end(list);
	return (len);
}
