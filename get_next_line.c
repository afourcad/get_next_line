/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                   :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:58:17 by afourcad          #+#    #+#             */
/*   Updated: 2016/12/13 21:16:38 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

//s occuper de bien fnir la copie entre tmp et line
//utiliser **line ou *line
//la fonction doit elle etre en void ou renvoyer un char *
void	ft_get_alloc_line(t_buff *buff, char *line)
{
	char	*tmp;
	int		size;

	size = buff->size_line + buff->eol;
	if ((tmp = (char *)malloc(sizeof(*tmp) * (size))) == NULL)
		return (NULL);
	if (*line != NULL)
		tmp = ft_memcpy(tmp, line, buff->size_line);
	tmp = ft_memcpy(tmp + buff->size_line, buff->buff + buff->start, buff->eol);
	buff->size_line = buff->size_line + buff->eol;
	return (tmp - buff->size_line);
}

int		ft_get_buff(t_buff *buff, char **line)
{
	int i;

	if (!(buff->buff))
		return (0);
	i = buff->start;
	while (i < buff->ret)
	{
		if (buff->buff[i] == EOL)
		{
			buff->eol = i;
			*line = ft_get_alloc_line(buff, *line);
			buff->start = i + 1;
			return (1);
		}
		i++;
	}
	buff->eol = buff->ret;
	*line = ft_get_alloc_line(buff, *line);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_buff	buff = {NULL, 0, 0, BUFF_SIZE, 0};

	if (buff.buff != NULL)
		if (ft_get_buff(&buff, line))
			return (1);
	buff.buff = ft_memalloc(BUFF_SIZE + 1);
	while ((buff.ret = read(fd, buff.buff, BUFF_SIZE)) > 0)
	{
		if (ft_get_buff(&buff, line))
			return (1);
	}
	if (buff.ret == -1)
		return (-1);
	return (0);
}
