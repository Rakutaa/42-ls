/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:13:23 by vtran             #+#    #+#             */
/*   Updated: 2020/02/08 17:05:29 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir_info	*ft_roll(t_dir_info *list)
{
	while (list && list->name)
		list = list->next;
	return (list);
}

/*
**to get the last linked list directory as top
*/

t_dir_info	*new_brank(t_dir_info *list, char *path)
{
	t_dir_info	*head;
	t_dir_info	*tail;
	t_dir_info	*headtail;
	t_dir_info	*last;

	last = ft_roll(list);
	tail = list;
	while (ft_strcmp(tail->next->path, path) != 0)
		tail = tail->next;
	head = tail->next;
	headtail = head;
	while (headtail->next->name)
		headtail = headtail->next;
	tail->next = last;
	headtail->next = list;
	return (head);
}

/*
**padding list other
*/

void		bring_me_max(t_dir_info *head, t_max *max_head)
{
	char		*path;
	t_dir_info	*tail;

	tail = ft_roll(head);
	path = ft_strdup(head->path);
	while (head != tail)
	{
		if (ft_strcmp(path, head->path) != 0)
		{
			max_head->next = init_head();
			max_head = max_head->next;
			free(path);
			path = ft_strdup(head->path);
		}
		set_max(head, max_head);
		head = head->next;
	}
	free(path);
}

void		sort(t_dir_info **head, t_flags *flags)
{
	flags->flag_r ? r_ascii_sort(head) : ascii_sort(head);
	if (flags->flag_t)
		flags->flag_r ? r_t_sort(head, 1) : t_sort(head, 1);
}

/*
**helper working in all the other cases than -rtR flags
*/

void		that(t_flags *flags, t_max *max_head, t_dir_info *head,
			const char *path)
{
	sort(&head, flags);
	head = ((flags->flag_r && flags->flag_cap) || (flags->flag_t &&
	flags->flag_cap)) ? new_brank(head, (char*)path) : head;
	bring_me_max(head, max_head);
	print_dir_cap(head, max_head, flags, 0);
	free_list_head(head, max_head);
}
