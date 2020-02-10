/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:35:12 by vtran             #+#    #+#             */
/*   Updated: 2020/02/08 14:38:07 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir_info	*init_element(void)
{
	t_dir_info	*new_info;

	new_info = (t_dir_info *)malloc(sizeof(*new_info));
	new_info->name = NULL;
	new_info->st_mode = 0;
	new_info->st_nlink = 0;
	new_info->st_uid = 0;
	new_info->st_gid = 0;
	new_info->size = 0;
	new_info->time = 0;
	new_info->blocks = 0;
	new_info->rights = NULL;
	new_info->prev_path = NULL;
	new_info->path = NULL;
	new_info->full_path = NULL;
	new_info->next = NULL;
	new_info->dir_date = 0;
	return (new_info);
}

/*
**initializing padding list;
*/

t_max		*init_head(void)
{
	t_max		*head;

	head = (t_max *)malloc(sizeof(*head));
	head->links = 0;
	head->user = 0;
	head->group = 0;
	head->size = 0;
	head->name = 0;
	head->blocks = 0;
	head->files = 0;
	head->dir_info = NULL;
	head->dir_path = NULL;
	head->dir_date = 0;
	head->next = NULL;
	return (head);
}
