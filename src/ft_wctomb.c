/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:13:59 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/07 08:14:43 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_wchar_len(wint_t org)
{
	if (org <= (MB_CUR_MAX == 1 ? 0xFF : 0x7F))
		return (1);
	if (org <= 0x7ff)
		return (2);
	if (org <= 0xffff)
		return (3);
	if (org <= 0x10ffff)
		return (4);
	return (-1);
}

int		ft_wctomb(char *tmp, wchar_t org)
{
	int		len;

	IF((len = ft_wchar_len(org)) == -1, -1);
	if (len == 1)
		tmp[0] = org;
	else if (len == 2)
	{
		tmp[0] = ((org >> 6) | 0xC0);
		tmp[1] = ((org & 0x3f) | 0x80);
	}
	else if (len == 3)
	{
		tmp[0] = ((org >> 12) | 0xE0);
		tmp[1] = (((org >> 6) & 0x3f) | 0x80);
		tmp[2] = ((org & 0x3f) | 0x80);
	}
	else if (len == 4)
	{
		tmp[0] = ((org >> 18) | 0xf0);
		tmp[1] = (((org >> 12) & 0x3f) | 0x80);
		tmp[2] = (((org >> 6) & 0x3f) | 0x80);
		tmp[3] = ((org & 0x3f) | 0x80);
	}
	return (len);
}
