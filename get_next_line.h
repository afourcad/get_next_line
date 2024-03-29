/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:52:53 by afourcad          #+#    #+#             */
/*   Updated: 2017/01/09 18:51:39 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 4
# define EOL '\n'

typedef struct	s_buff
{
	char	buff[BUFF_SIZE];
	int		eol;
	int		ret;
	int		size_line;
}				t_buff;
int				get_next_line(const int fd, char **line);

#endif
