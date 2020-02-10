/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:31:49 by vtran             #+#    #+#             */
/*   Updated: 2020/02/08 14:32:21 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_head(t_dir_info *head)
{
	t_dir_info	*tmp;

	tmp = head;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void	free_list_s(t_dir_info *head)
{
	if (head->next)
		free_list_s(head->next);
	if (head->name)
		free_list_elem(head);
	free(head);
}

void	free_list(t_dir_info *head)
{
	if (head->next)
		free_list(head->next);
	if (head->name)
		free_list_elem(head);
}

void	free_max(t_max *max)
{
	t_max	*tmp;

	tmp = max;
	while (max)
	{
		tmp = max->next;
		free(max);
		max = tmp;
	}
}

void	free_list_head(t_dir_info *head, t_max *max)
{
	free_list(head);
	free_max(max);
	free_head(head);
}
