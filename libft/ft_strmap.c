/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:56:05 by afourcad          #+#    #+#             */
/*   Updated: 2016/11/14 16:18:38 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			str_fresh[i] = f(s[i]);
			i++;
		}
		return (str_fresh);
	}
	return (NULL);
}
