/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:09:07 by afourcad          #+#    #+#             */
/*   Updated: 2016/12/05 19:35:41 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char	*ft_stralloc(char **line, char *buff, int loop, int ret)
{
	char	*tmp;
	char	size;

	size = BUFF_SIZE * loop;
	if ((tmp = (char *)malloc(sizeof(*tmp) * (size + ret))) == NULL)
		return (NULL);
	tmp = ft_memcpy(tmp, *line, size);
	tmp = ft_memcpy(tmp + size, buff, ret);
	free(*line);
	return (tmp);
}

static int	ft_find_n(char *src, int ret)
{
	int		i;

	i = 0;
	while (i < ret)
	{
		if (src[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE];
	int			ret;
	static int	i;
	//static char	*tmp;
	int			loop;

	loop = 0;
	//tmp = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if ((i = ft_find_n(buff, ret)))
		{
			ft_putchar('Y');
			*line = ft_stralloc(line, buff, loop, i);
			//tmp = ft_stralloc(&tmp, buff + i, 0, BUFF_SIZE - i);
			return (1);
		}
		else
			*line = ft_stralloc(line, buff, loop, ret);	
		++loop;
	}
	return (0);
}
