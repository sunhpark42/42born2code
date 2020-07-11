/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:41:25 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/11 16:10:37 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	del_node(void *content)
{
	if (content)
		printf("%s is deleted\n", content);
	else
		printf("no content\n");
}

int		main(void)
{
	t_list			*lst;
	t_list			*new;
	t_list			*ptr;
	void			(*del)(void *);

	del = del_node;
	lst = ft_lstnew("123");
	if (!lst)
		return (0);
	new = ft_lstnew("456");
	if (!new)
		return (0);
	ft_lstadd_front(&lst, new);
	ptr = lst;
	while(ptr)
	{
		ft_putstr_fd(ptr->content, 1);
		printf("\n");
		ptr = ptr->next;
	}
	ptr = lst->next;
	ft_lstdelone(ptr, del);
	ft_lstclear(&lst, del);
	return (0);
}
