/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:51:11 by afourcad          #+#    #+#             */
/*   Updated: 2016/11/09 16:13:24 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	i = (dst < src) ? 0 : n;
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (dst < src)
		while (i < n)
		{
			tmp_dst[i] = tmp_src[i];
			i++;
		}
	else
		while (i)
		{
			tmp_dst[i - 1] = tmp_src[i - 1];
			i--;
		}
	return (dst);
}
