/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:08:58 by vtran             #+#    #+#             */
/*   Updated: 2020/02/08 15:56:02 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	mini_r_ascii_sort(t_dir_info **head)
{
	int			swapped;
	t_dir_info	*b;
	t_dir_info	*c;
	t_dir_info	*n;

	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		set_start(&b, &c, &n, *head);
		while (n->name != NULL && swapped == 0)
		{
			if (ft_strcmp(c->name, n->name) < 0)
			{
				swap(&b, &c, &n, head);
				swapped = 1;
			}
			else
				move_one(&b, &c, &n);
		}
	}
}

/*
**file sortter when no -t or -r
*/

void	mini_ascii_sort(t_dir_info **head)
{
	int			swapped;
	t_dir_info	*b;
	t_dir_info	*c;
	t_dir_info	*n;

	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		set_start(&b, &c, &n, *head);
		while (n->name != NULL && swapped == 0)
		{
			if (ft_strcmp(c->name, n->name) > 0)
			{
				swap(&b, &c, &n, head);
				swapped = 1;
			}
			else
				move_one(&b, &c, &n);
		}
	}
}

/*
**file sortter with -t
*/

void	mini_t_sort(t_dir_info **head)
{
	int			swapped;
	t_dir_info	*b;
	t_dir_info	*c;
	t_dir_info	*n;

	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		set_start(&b, &c, &n, *head);
		while (n->name != NULL && swapped == 0)
		{
			if ((c->time < n->time ||
			((ft_strcmp(c->name, n->name) > 0) && c->time == n->time)))
			{
				swap(&b, &c, &n, head);
				swapped = 1;
			}
			else
				move_one(&b, &c, &n);
		}
	}
}

/*
**file sortter with -tr
*/

void	mini_t_r_sort(t_dir_info **head)
{
	int			swapped;
	t_dir_info	*b;
	t_dir_info	*c;
	t_dir_info	*n;

	swapped = 1;
	while (swapped == 1)
	{
		swapped = 0;
		set_start(&b, &c, &n, *head);
		while (n->name != NULL && swapped == 0)
		{
			if ((c->time > n->time ||
			((ft_strcmp(c->name, n->name) < 0) && c->time == n->time)))
			{
				swap(&b, &c, &n, head);
				swapped = 1;
			}
			else
				move_one(&b, &c, &n);
		}
	}
}
