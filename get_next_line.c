/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:09:07 by afourcad          #+#    #+#             */
/*   Updated: 2016/12/06 19:31:11 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char	*ft_stralloc(char **line, char *buff, int loop, int ret)
{
	char	*tmp;
	int		size;

	size = BUFF_SIZE * loop;
	if ((tmp = (char *)malloc(sizeof(char) * (size + ret))) == NULL)
		return (NULL);
	tmp = ft_memcpy(tmp, *line, size);
	tmp = ft_memcpy(tmp + size, buff, ret);
	tmp[size + ret] = '\0';
	free(*line);
	*line = NULL;
	return (tmp - size);
}

static int	ft_find_n(char *buff, int ret)
{
	int		i;

	i = 0;
	while (i <= ret)
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_get_read_line(int fd, char **line, char *buff)
{
	int		ret;
	int		loop;
	int		i;

	loop = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((i = ft_find_n(buff, ret)) >= 0)
		{
			*line = ft_stralloc(line, buff, loop, i);
			//printf("loop: %d // ret = %d // line = |%s|\n", loop, ret, *line);
			buff = ft_stralloc(&buff, buff + i, 0, BUFF_SIZE - i);
			printf("BUFF: |%s|\n", buff);
			i = BUFF_SIZE - i;
			return (1);
		}
		else
		{
			*line = ft_stralloc(line, buff, loop, ret);	
		}
		++loop;
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE + 1];

 	if (*line != NULL)
	{
		free(*line);
		*line = NULL;
	}
	if (*buff)
	{
		
	}
	/*if (!tmp)
	{
		ft_stralloc	
	}*/
	
	return (ft_get_read_line(fd, line, buff));
}
