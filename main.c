/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <szeftyr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:14:14 by szeftyr           #+#    #+#             */
/*   Updated: 2019/11/03 13:30:54 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
    // int     fd0,fd2,fd3,fd4,i;
    // char    *str;
    // fd3 = open("gnl11_1.txt", O_RDONLY);
    // fd2 = open("empty.txt", O_RDONLY);
    // fd4 = open("gnl7_1.txt", O_RDONLY);
    // // fd4 = open("", O_RDONLY);

    // i = 0;
    // printf("%i fd4 %i ", i++, get_next_line(fd4, &str));
    // printf ("%s\n", str);
    // free(str);
    // printf("%i fd2 %i ", i++, get_next_line(fd2, &str));
    // printf ("%s\n", str);
    // free(str);
    // printf("%i fd4 %i ", i++, get_next_line(fd4, &str));
    // printf ("%s\n", str);
    // free(str);
    
    // printf("%i fd4 %i ", i++, get_next_line(fd4, &str));
    // printf ("%s\n", str);
    // free(str);
    // printf("%i fd3 %i ", i++, get_next_line(fd3, &str));
    // printf ("%s\n", str);
    // // free(str);
    // printf("%i fd4 %i ", i++, get_next_line(fd4, &str));
    // printf ("%s\n", str);
    // free(str);
    // printf("%i fd3 %i ", i++, get_next_line(fd3, &str));
    // printf ("%s\n", str);
    // // free(str);
    // printf("%i fd4 %i ", i++, get_next_line(fd4, &str));
    // printf ("%s\n", str);
    // // free(str);

    int     fd0, fd1, fd2,fd3,fd4,i;
    char    *str;
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