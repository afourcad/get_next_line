/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:09:07 by afourcad          #+#    #+#             */
/*   Updated: 2016/12/02 17:29:33 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_cpy_buff(char *src, char **dest, int ret)
{
	char	*str2;
	int		i;

	i = 0;
	while (i < ret)
	{
		if (src[i] == '\n')
		{
			*dest = ft_strncat(*dest, src, i);
			return (1);
		}
		else if (src[i] == '\0')
		{
			*dest = ft_strncat(*dest, src, i);
			return (0);
		}
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	char	buff[BUFF_SIZE];
	int		ret;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if ((ft_cpy_buff(buff, *line, ret)) == 1)
			return (1);
		else if ((ft_cpy_buff(buff, *line, ret)) == 1)
			return (0);
	}
}
