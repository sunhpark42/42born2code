/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:23:37 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/18 15:53:08 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list			*del_next_lst;

	if (!lst)
		return ;
	del_next_lst = *lst;
	while (del_next_lst)
	{
		*lst = (*lst)->next;
		ft_lstdelone(del_next_lst, del);
		del_next_lst = *lst;
	}
	*lst = 0;
}
