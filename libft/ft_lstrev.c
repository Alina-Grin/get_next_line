/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:06:18 by szeftyr           #+#    #+#             */
/*   Updated: 2019/09/24 16:16:56 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **begin_list)
{
	t_list	*cur;
	t_list	*next;
	t_list	*prev;

	if (!*begin_list)
		return ;
	prev = NULL;
	cur = *begin_list;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*begin_list = prev;
}
