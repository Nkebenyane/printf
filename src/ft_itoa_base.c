/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 07:53:54 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/07 07:54:11 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa_base(uintmax_t n, int8_t base, const char *spec)
{
	int8_t		len;
	char		*ret;

	if (base < 2)
		return (0);
	len = ft_nbrlen_base(n, base);
	IF((ret = ft_strnew(len)) == NULL, NULL);
	while (--len)
	{
		ret[len] = spec[n % base];
		n /= base;
	}
	ret[len] = spec[n % base];
	return (ret);
}
