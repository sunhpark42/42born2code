/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:15:09 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/11 14:40:03 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int			cnt;
	t_list		*p_lst;

	cnt = 0;
	p_lst = lst;
	while (p_lst)
	{
		cnt++;
		p_lst = p_lst->next;
	}
	return (cnt);
}
