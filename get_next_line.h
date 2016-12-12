/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:52:53 by afourcad          #+#    #+#             */
/*   Updated: 2016/12/12 19:31:02 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 20
# define EOL '\n'

typedef struct	s_tmp
{
	char	*tmp;
	int	ln;
}				t_tmp;

int				get_next_line(const int fd, char **line);

#endif
