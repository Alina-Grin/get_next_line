/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <szeftyr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:39:44 by szeftyr           #+#    #+#             */
/*   Updated: 2019/11/04 12:09:49 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 256

# include "libft/includes/libft.h"

typedef struct			s_gnl_list
{
	int					fd;
	char				*content;
	struct s_gnl_list	*next;
}						t_gnl_list;

int						get_next_line(const int fd, char **line);

#endif
