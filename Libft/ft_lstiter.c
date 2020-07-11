/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 15:33:25 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/11 15:46:02 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list			*p_lst;

	p_lst = lst;
	while(p_lst)
	{
		f(p_lst->content);
		p_lst = p_lst->next;
	}
}
