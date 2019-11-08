/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <szeftyr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:53:33 by szeftyr           #+#    #+#             */
/*   Updated: 2019/11/03 14:51:35 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

t_gnl_list	*newel(const int fd)
{
	t_gnl_list	*new;

	if (!(new = (t_gnl_list *)malloc(sizeof(t_gnl_list))))
		return (NULL);
	new->fd = fd;
	new->content = ft_strnew(0);
	new->next = NULL;
	return (new);
}

t_gnl_list	*find_fd(t_gnl_list *data, const int fd)
{
	t_gnl_list	*tmp;
	t_gnl_list	*cur;

	if (!data)
		return (NULL);
	cur = data;
	while (cur->fd != fd)
	{
		if (cur->next == NULL)
		{
			tmp = newel(fd);
			cur->next = tmp;
		}
		cur = cur->next;
	}
	return (cur);
}

char		*check_static(char *stat, char **str, char **line)
{
	char	*tmp_str;
	char	*ptr;

	if ((ptr = ft_strchr(stat, '\n')))
	{
		if (!(*str = ft_strsub(stat, 0, (ptr - stat))))
			return (NULL);
		tmp_str = stat;
		if (!(stat = ft_strdup(ptr + 1)))
			return (NULL);
		free(tmp_str);
		ft_strclr(ptr);
	}
	else
	{
		*str = ft_strdup(stat);
		ft_strclr(stat);
	}
	ft_strcpy(*line, *str);
	return (stat);
}

char		*check_read(char *stat, char **str, char *buff, char **line)
{
	char				*ptr;
	char				*tmp_str;

	if (!(tmp_str = ft_strjoin(stat, buff)))
		return (NULL);
	free(stat);
	stat = tmp_str;
	if ((ptr = ft_strchr(stat, '\n')))
	{
		if (!(*str = ft_strsub(stat, 0, (ptr - stat))))
			return (NULL);
		tmp_str = stat;
		if (!(stat = ft_strdup(ptr + 1)))
			return (NULL);
		free(&(*tmp_str));
		ft_strclr(ptr);
	}
	else
		*str = NULL;
	if (*str)
		ft_strcpy(*line, *str);
	return (stat);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl_list	*data;
	t_gnl_list			*ptr_fd;
	int					read_bytes;
	char				buff[BUFF_SIZE + 1];
	char				**tmp;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (data == NULL)
		data = newel(fd);
	ptr_fd = find_fd(data, fd);
	tmp = line;
	while ((read_bytes = read(fd, buff, BUFF_SIZE)))
	{
		buff[read_bytes] = '\0';
		ptr_fd->content = check_read(ptr_fd->content, tmp, buff, line);
		if (*line)
			return (1);
	}
	if (read_bytes == 0 && (*ptr_fd->content))
	{
		ptr_fd->content = check_static(ptr_fd->content, tmp, line);
		return (1);
	}
	return (0);
}
