/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorttrcap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:59:39 by vtran             #+#    #+#             */
/*   Updated: 2020/02/08 17:03:14 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		m_swap(t_max **b, t_max **c, t_max **n, t_max **h)
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

static void		m_setstart(t_max **b, t_max **c, t_max **n, t_max *s)
{
	*b = NULL;
	*c = s;
	*n = s->next;
}

static void		m_moveone(t_max **b, t_max **c, t_max **n)
{
	*b = *c;
	*c = *n;
	*n = (*n)->next;
}

void			s_r_t_sort(t_max **start)
{
	int		swapped;
	t_max	*b;
	t_max	*c;
	t_max	*n;

	if (start == NULL)
		return ;
	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		m_setstart(&b, &c, &n, *start);
		while (n->next->name && swapped == 0)
		{
			if ((c->dir_date > n->dir_date &&
			ft_strcmp(c->dir_path, n->dir_path) > 0))
			{
				m_swap(&b, &c, &n, start);
				swapped = 1;
			}
			else
				m_moveone(&b, &c, &n);
		}
	}
}
