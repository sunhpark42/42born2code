/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:23:37 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/11 16:23:18 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list			*del_next_lst;

	del_next_lst = lst->next;
	while (lst)
	{
		ft_lstdelone(lst, del);
		lst = del_next_lst;
		del_next_lst = lst->next;
	}
}
