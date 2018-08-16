/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:20:35 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/06/12 16:58:04 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	d;
	size_t	start;
	char	**str;

	str = NULL;
	i = 0;
	d = 0;
	if (!s || !(str = (char **)malloc(sizeof(*str) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] && s[i] != c && i < ft_strlen(s) + 1)
			i++;
		if (i > start)
		{
			str[d++] = ft_strsub(s, start, (i - start));
		}
		i++;
	}
	str[d] = NULL;
	return (str);
}
