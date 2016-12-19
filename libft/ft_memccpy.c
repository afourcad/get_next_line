/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:50:20 by afourcad          #+#    #+#             */
/*   Updated: 2016/11/15 18:47:56 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	char			*tmp_src;
	char			*tmp_dest;

	tmp_src = (char *)src;
	tmp_dest = (char *)dest;
	i = 0;
	while (n > 0)
	{
		tmp_dest[i] = tmp_src[i];
		i++;
		if (tmp_src[i - 1] == c)
			return (tmp_dest + i);
		n--;
	}
	return (NULL);
}
