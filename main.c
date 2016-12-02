/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:59:56 by etrobert          #+#    #+#             */
/*   Updated: 2016/12/02 17:32:30 by afourcad         ###   ########.fr       */
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
	char	*str;
	int		fd;

	if (argc != 2)
	{
		printf("Too few parameters !\n");
		return (0);
	}
	str = NULL;
	if ((fd = open(argv[1]), O_RDONLY) == -1)
		return (0);
	while ((get_next_line(fd, &str)) == 1)
		;
	ft_putstr(str);
	return (0);
}
