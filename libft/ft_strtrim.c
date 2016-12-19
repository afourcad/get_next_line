/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:18:17 by afourcad          #+#    #+#             */
/*   Updated: 2016/11/15 20:42:42 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_bool(const char s)
{
	if (s == ' ' || s == '\t' || s == '\n')
		return (1);
	else
		return (0);
}

static int		ft_len(const char *s)
{
	int	len;

	len = ft_strlen(s) - 1;
	if (len <= 0)
		len = 0;
	while (ft_bool(s[len]) == 1)
		len--;
	return (len + 1);
}

char			*ft_strtrim(const char *s)
{
	int		len;
	char	*str;

	if (!s)
		return (NULL);
	while (ft_bool(*s) == 1)
		s++;
	len = ft_len(s);
	str = ft_strndup(s, len);
	return (str);
}
