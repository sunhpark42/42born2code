/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 15:37:57 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/16 16:08:08 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*new_lst;
	t_list			*ret_lst;
	t_list			*p_lst;

	if (!lst)
		return (0);
	ret_lst = ft_lstnew(f(lst->content));
	if (!ret_lst)
		return (0);
	p_lst = lst->next;
	while (p_lst)
	{
		new_lst = ft_lstnew(f(p_lst->content));
		if (!new_lst)
		{
			ft_lstclear(&ret_lst, del);
			return (0);
		}
		ft_lstadd_back(&ret_lst, new_lst);
		p_lst = p_lst->next;
	}
	return (ret_lst);
}
