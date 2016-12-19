/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:14 by afourcad          #+#    #+#             */
/*   Updated: 2016/11/15 18:10:59 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char		*ft_next_word(const char *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	while (s[i] == c && s[i])
		i++;
	return ((char*)s + i);
}

static unsigned int	ft_nbr_words(const char *s, char c)
{
	unsigned int	nbr_words;

	nbr_words = 0;
	while (*s)
	{
		s = ft_next_word(s, c);
		nbr_words++;
	}
	return (nbr_words);
}

static int			ft_word_len(const char *s, char c)
{
	unsigned int	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**split;
	unsigned int	i;

	if (!s || !c || c == '\0')
		return (NULL);
	i = 0;
	while (*s == c && *s)
		s++;
	if ((split = malloc(sizeof(char *) * (ft_nbr_words(s, c) + 1))) == NULL)
		return (NULL);
	while (*s)
	{
		split[i] = ft_strndup(s, ft_word_len(s, c));
		s = ft_next_word(s, c);
		i++;
	}
	split[i] = NULL;
	return (split);
}
