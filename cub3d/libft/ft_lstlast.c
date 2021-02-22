/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:17:57 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/18 15:51:34 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list		*p_lst;

	p_lst = lst;
	if (!lst)
		return (0);
	while (p_lst->next)
	{
		p_lst = p_lst->next;
	}
	return (p_lst);
}
