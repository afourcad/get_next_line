/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:47:47 by afourcad          #+#    #+#             */
/*   Updated: 2016/11/16 18:32:17 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	dst_lgt;
	size_t	j;
	size_t	src_lgt;

	dst_lgt = 0;
	j = 0;
	src_lgt = ft_strlen(src);
	while (dst_lgt < size && dst[dst_lgt])
		dst_lgt++;
	j = dst_lgt;
	while (j < size - 1 && *src && src)
	{
		dst[j] = *src;
		j++;
		src++;
	}
	if (j > dst_lgt)
		dst[j] = '\0';
	return (dst_lgt + src_lgt);
}
