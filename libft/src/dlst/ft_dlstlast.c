/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:27:15 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 13:27:15 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstlast(t_dlist *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}
