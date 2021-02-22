/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:10:37 by sunhpark          #+#    #+#             */
/*   Updated: 2020/07/11 14:39:47 by sunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list			*new_lst;

	new_lst = (t_list*)malloc(sizeof(t_list));
	if (!new_lst)
		return (0);
	new_lst->content = content;
	new_lst->next = NULL;
	return (new_lst);
}
