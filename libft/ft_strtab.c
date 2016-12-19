/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:43:13 by afourcad          #+#    #+#             */
/*   Updated: 2016/11/24 19:03:03 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtab(int i, int j)
{
	char	**tab;

	tab = (char **)malloc(sizeof(*tab) * (i + 1));
	tab[i + 1] = NULL;
	i = 0;
	while (tab[i])
	{
		tab[i] = (char *)malloc(sizeof(tab) * (j + 1));
		tab[i][j + 1] = '\0';
		i++;
	}
	return (tab);
}
