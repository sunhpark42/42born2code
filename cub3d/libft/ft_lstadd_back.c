/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:19:33 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/11 14:38:40 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*p_lst;

	p_lst = *lst;
	if (!(*lst))
		*lst = new;
	else
	{
		while (p_lst && p_lst->next)
		{
			p_lst = p_lst->next;
		}
		p_lst->next = new;
	}
}
