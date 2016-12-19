/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:47:57 by afourcad          #+#    #+#             */
/*   Updated: 2016/11/15 18:24:13 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str_fresh;
	unsigned int	i;

	if (s && f)
	{
		if ((str_fresh = ft_strnew(ft_strlen(s))) == NULL)
			return (NULL);
		i = 0;
		while (s[i])
		{
			str_fresh[i] = f(i, s[i]);
			i++;
		}
		return (str_fresh);
	}
	return (NULL);
}
