/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:19:01 by vtran             #+#    #+#             */
/*   Updated: 2020/02/08 17:19:04 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir_info	*r_t_s_sort(t_dir_info **start)
{
	int			swapped;
	t_dir_info	*b;
	t_dir_info	*c;
	t_dir_info	*n;

	if (start == NULL)
		return (NULL);
	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		set_start(&b, &c, &n, *start);
		while (n->name && swapped == 0)
		{
			if (c->time > n->time)
			{
				swap(&b, &c, &n, start);
				swapped = 1;
			}
			else
				move_one(&b, &c, &n);
		}
	}
	return (*start);
}

/*
** r_t_sort
*/

t_dir_info	*r_t_sort(t_dir_info **start, int swapped)
{
	t_dir_info	*b;
	t_dir_info	*c;
	t_dir_info	*n;

	while (swapped == 1)
	{
		swapped = 0;
		set_start(&b, &c, &n, *start);
		while (n->name && swapped == 0)
		{
			if ((c->time > n->time && ft_strcmp(c->path, n->path) == 0) ||
			(c->time == n->time && ft_strcmp(c->path, n->path) == 0 &&
			ft_strcmp(c->name, n->name) < 0) ||
			(((ft_strcmp(c->path, n->prev_path) < 0
			|| ft_strcmp(c->prev_path, n->prev_path) == 0)) &&
			c->dir_date > n->dir_date))
			{
				swap(&b, &c, &n, start);
				swapped = 1;
			}
			else
				move_one(&b, &c, &n);
		}
	}
	return (*start);
}

/*
**time sort
*/

void		t_sort(t_dir_info **start, int swapped)
{
	t_dir_info	*b;
	t_dir_info	*c;
	t_dir_info	*n;

	while (swapped == 1)
	{
		swapped = 0;
		set_start(&b, &c, &n, *start);
		while (n->name != NULL && swapped == 0)
		{
			if ((c->time < n->time && ft_strcmp(c->path, n->path) == 0) ||
			(c->time == n->time && ft_strcmp(c->path, n->path) == 0 &&
			ft_strcmp(c->name, n->name) > 0) ||
			(ft_strcmp(c->path, n->prev_path) < 0) ||
			(ft_strcmp(c->prev_path, n->prev_path) == 0 &&
			c->dir_date < n->dir_date))
			{
				swap(&b, &c, &n, start);
				swapped = 1;
			}
			else
				move_one(&b, &c, &n);
		}
	}
}

/*
**reverse
*/

void		r_ascii_sort(t_dir_info **start)
{
	int			swapped;
	t_dir_info	*b;
	t_dir_info	*c;
	t_dir_info	*n;

	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		set_start(&b, &c, &n, *start);
		while (n->name != NULL && swapped == 0)
		{
			if ((ft_strcmp(c->name, n->name) < 0 &&
			ft_strcmp(c->path, n->path) == 0)
			|| (ft_strcmp(c->path, n->prev_path) < 0) ||
			((ft_strcmp(c->path, n->path) < 0) &&
			ft_strcmp(c->prev_path, n->prev_path) == 0))
			{
				swap(&b, &c, &n, start);
				swapped = 1;
			}
			else
				move_one(&b, &c, &n);
		}
	}
}

void		ascii_sort(t_dir_info **start)
{
	int			swapped;
	t_dir_info	*before;
	t_dir_info	*current;
	t_dir_info	*next;

	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		set_start(&before, &current, &next, *start);
		while (next->name != NULL && swapped == 0)
		{
			if (ft_strcmp(current->path, next->path) > 0 ||
			(ft_strcmp(current->path, next->path) == 0 &&
			ft_strcmp(current->name, next->name) > 0))
			{
				swap(&before, &current, &next, start);
				swapped = 1;
			}
			else
				move_one(&before, &current, &next);
		}
	}
}
