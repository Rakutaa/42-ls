/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorthelppers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:09:51 by vtran             #+#    #+#             */
/*   Updated: 2020/02/08 15:57:18 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap(t_dir_info **b, t_dir_info **c, t_dir_info **n, t_dir_info **h)
{
	if (*b == NULL)
	{
		(*c)->next = (*n)->next;
		(*n)->next = *c;
		*h = *n;
	}
	else
	{
		(*b)->next = (*n);
		(*c)->next = (*n)->next;
		(*n)->next = (*c);
	}
}

void	set_start(t_dir_info **b, t_dir_info **c, t_dir_info **n,
		t_dir_info *s)
{
	*b = NULL;
	*c = s;
	*n = s->next;
}

void	move_one(t_dir_info **b, t_dir_info **c, t_dir_info **n)
{
	*b = *c;
	*c = *n;
	*n = (*n)->next;
}
