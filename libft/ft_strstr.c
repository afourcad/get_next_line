/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:55:27 by afourcad          #+#    #+#             */
/*   Updated: 2016/11/09 19:54:36 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	while (*big)
	{
		i = 0;
		while (little[i] == big[i] && little[i] && big[i])
			i++;
		if (!little[i])
			return ((char *)big);
		big++;
	}
	return (NULL);
}
