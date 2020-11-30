/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:14:14 by szeftyr           #+#    #+#             */
/*   Updated: 2020/11/30 16:00:00 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
	int	fd0, fd1, fd2,fd3,fd4,i;
	char	*str;
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = fd1;

	str = NULL;
	while (get_next_line(fd3, &str) == 1)
	{
		printf("%s\n", str);
		ft_memdel((void**)&str);
		fd3 = fd3 == fd1 ? fd2 : fd1;
	}
	ft_memdel((void**)&str);
	close(fd1);
	close(fd2);
	return (0);

	return (0);
}