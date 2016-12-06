/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:59:56 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/06 19:03:17 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"


int		main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc != 2)
	{
		printf("Parameters error !\n");
		return (0);
	}
	line = NULL;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (-1);
	while ((get_next_line(fd, &line)) == 1)
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	return (0);
}
