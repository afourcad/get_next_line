/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:09:07 by afourcad          #+#    #+#             */
/*   Updated: 2016/12/12 19:51:13 by afourcad         ###   ########.fr       */
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
		if (buff[i] == EOL)
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_find_tmp_n(t_tmp *tmp, char **line)
{
	int		i;
	char	*tmp2;

	i = 0;
	tmp2 = tmp->tmp;
	while (i < tmp->ln)
	{
		if (tmp->tmp[i] == EOL)
		{
			tmp->ln = tmp->ln - i;
			free(tmp->tmp);
			tmp->tmp = ft_memalloc(tmp->ln);
			tmp->tmp = ft_memcpy(tmp->tmp, tmp2 + i + 1, tmp->ln);
			free(tmp2);
			return (1);
		}
		*line[i] = tmp->tmp[i];
		i++;
	}
	free(tmp2);
	ft_memdel((void**)tmp->tmp);
	tmp->ln = 0;
	return (0);
}
static int	ft_get_read_line(int fd, char **line, t_tmp *tmp, int *loop)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int		i;

	(void)tmp;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((i = ft_find_n(buff, ret)) >= 0)
		{
			*line = ft_stralloc(line, buff, loop, i);
			printf("loop: %d // ret = %d // line = |%s|\n", *loop, ret, *line);
			*tmp = ft_memcpy(*tmp, buff + i + 1, BUFF_SIZE - i - 1);
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
	static t_tmp	*tmp;
	int			loop;

	free(*line);
	*line = NULL;
	tmp->tmp = NULL;
	loop = 0;
	if (tmp->tmp != NULL) //si mon tmp contient l ancien buff et qu il contient un EOL
		if(ft_get_read_line(tmp, line))
			return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((i = ft_find_n(buff, ret)) >= 0)
		{
			*line = ft_stralloc(line, buff, loop, i);
			printf("loop: %d // ret = %d // line = |%s|\n", *loop, ret, *line);
			*tmp = ft_memcpy(*tmp, buff + i + 1, BUFF_SIZE - i - 1);
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
