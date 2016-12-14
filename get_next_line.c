/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                   :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:58:17 by afourcad          #+#    #+#             */
/*   Updated: 2016/12/14 19:51:10 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_get_alloc_line(t_buff *buff, char *line)
{
	char	*tmp;
	int		size;

	size = buff->size_line + buff->eol;
	if ((tmp = (char *)malloc(sizeof(*tmp) * (size))) == NULL)
		return (NULL);
	if (line != NULL)
		tmp = ft_memcpy(tmp, line, buff->size_line);
	tmp = ft_memadd(tmp, buff->buff, buff->size_line, buff->eol);
	tmp[size] = '\0';
	buff->size_line = buff->size_line + buff->eol;
	return (tmp);
}

int		ft_get_buff(t_buff *buff, char **line)
{
	int i;

	if (buff->ret == 0)
		return (0);
	i = 0;
	while (i < buff->ret)
	{
		if (buff->buff[i] == EOL || buff->buff[i] == EOF)
		{
			buff->eol = i;
			*line = ft_get_alloc_line(buff, *line);
			buff->ret = buff->ret - i - 1;
			ft_memmove(buff->buff, buff->buff + i + 1, buff->ret);
			return (1);
		}
		i++;
	}
	buff->eol = i;
	*line = ft_get_alloc_line(buff, *line);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_buff	buff = {.eol = 0, .ret = 0, .size_line = 0};

	free(*line);
	*line = NULL;
	if (buff.ret != 0)
		if (ft_get_buff(&buff, line))
			return (1);
	while ((buff.ret = read(fd, buff.buff, BUFF_SIZE)) > 0)
	{
		if (ft_get_buff(&buff, line))
		{
			buff.size_line = 0;
			return (1);
		}
	}
	if (buff.ret == -1)
		return (-1);
	return (0);
}
