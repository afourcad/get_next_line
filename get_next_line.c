/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:09:07 by afourcad          #+#    #+#             */
/*   Updated: 2016/12/07 19:11:28 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char	*ft_stralloc(char **line, char *buff, int *loop, int ret)
{
	char	*tmp;
	int		size;

	size = BUFF_SIZE * (*loop);
	printf("loop: %d\n", *loop);
	if ((tmp = (char *)malloc(sizeof(char) * (size + ret))) == NULL)
		return (NULL);
	if (*line != NULL)
		tmp = ft_memcpy(tmp, *line, size);
	tmp = ft_memcpy(tmp + size, buff, ret);
	tmp[size + ret] = '\0';
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

static int	ft_get_read_line(int fd, char **line, char *tmp, int *loop)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int		i;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((i = ft_find_n(buff, ret)) >= 0)
		{
			*line = ft_stralloc(line, buff, loop, i);
			printf("loop: %d // ret = %d // line = |%s|\n", *loop, ret, *line);
			tmp = ft_memcpy(tmp, buff + i + 1, BUFF_SIZE - i - 1);
			i = BUFF_SIZE - i;
			return (1);
		}
		else
		{
			*line = ft_stralloc(line, buff, loop, ret);	
		}
		++(*loop);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*tmp;
	static int	i;
	int			loop;

	free(*line);
	*line = NULL;
	tmp = NULL;
	i = BUFF_SIZE;
	loop = 0;
	if (tmp != NULL && (i = ft_find_n(tmp, i)) >= 0)
	{
		*line = ft_stralloc(line, tmp, &loop, i);
		tmp = ft_stralloc(&tmp, tmp + i + 1, &loop, BUFF_SIZE - i - 1);
		return (1);
	}
	else if (tmp != NULL)
	{
		*line = ft_stralloc(line, tmp, &loop, i);	
		++loop;
	}
	return (ft_get_read_line(fd, line, tmp, &loop));
}
