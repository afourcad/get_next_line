/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:55:06 by afourcad          #+#    #+#             */
/*   Updated: 2016/11/09 19:56:09 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	while (*big && n)
	{
		i = 0;
		while (big[i] && little[i] && i < n && big[i] == little[i])
			i++;
		if (!little[i])
			return ((char *)big);
		n--;
		big++;
	}
	return (NULL);
}
