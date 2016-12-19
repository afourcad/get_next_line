/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:45:11 by afourcad          #+#    #+#             */
/*   Updated: 2016/11/14 16:17:19 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*str_join;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = 0;
	if ((str_join = ft_strndup(s1, i + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	while (s2[j])
	{
		str_join[i] = s2[j];
		i++;
		j++;
	}
	str_join[i] = '\0';
	return (str_join);
}
