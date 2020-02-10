/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtrcap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:06:15 by vtran             #+#    #+#             */
/*   Updated: 2020/02/08 17:11:35 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_dir_t_l(t_max *max_head, t_flags *flags)
{
	t_max		*tmp;
	t_dir_info	*temp;

	tmp = max_head;
	while (max_head->name)
	{
		temp = max_head->dir_info;
		if (tmp != max_head)
			ft_printf("%s:\n", max_head->dir_path);
		ft_printf("total %d\n", max_head->blocks);
		while (temp->name)
		{
			print_magic(temp, max_head, flags);
			temp = temp->next;
		}
		max_head = max_head->next;
		if (max_head->name)
			ft_printf("\n");
	}
}

/*
**-rtR flag without l
*/

static void	print_dir_t_s(t_max *max, t_flags *flags, unsigned int i,
			int cols)
{
	struct winsize	w;
	int				tw;
	t_max			*tmp;
	t_dir_info		*temp;

	tmp = max;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	tw = w.ws_col;
	while (max->name)
	{
		temp = max->dir_info;
		tmp != max ? ft_printf("%s:\n", max->dir_path) : 0;
		cols = tw / (max->name + 1) > 0 ? tw / (max->name + 1) : 1;
		while (temp->name)
		{
			if (i % cols == 0 && i != 0 && i != max->files)
				ft_putchar('\n');
			print_magic(temp, max, flags);
			temp = temp->next;
			i++;
		}
		max = max->next;
		i = 0;
		max->name ? ft_printf("\n\n") : ft_putchar('\n');
	}
}

static void	pls_mercy(t_max *max, t_flags *flags)
{
	t_max			*tmp;
	t_max			*super_temp;

	if (max->next->name > 0)
		s_r_t_sort(&max);
	max->dir_info = r_t_sort(&max->dir_info, 1);
	tmp = max;
	tmp = tmp->next;
	while (tmp->name > 0)
	{
		r_t_s_sort(&tmp->dir_info);
		tmp = tmp->next;
	}
	super_temp = max;
	flags->flag_l ? print_dir_t_l(max, flags) :
	print_dir_t_s(max, flags, 0, 0);
	while (max->name)
	{
		free_list_s(max->dir_info);
		free(max->dir_path);
		max = max->next;
	}
	free_max(super_temp);
}

/*
**making padding list and putting content inside of it
**(linked list where is a pointer to a content linked list trR)
*/

static void	bring_me_max_t_r(t_dir_info *head, t_max *max_head, t_dir_info *tmp)
{
	char			*path;

	path = ft_strdup(head->path);
	max_head->dir_path = ft_strdup(path);
	max_head->dir_info = head;
	max_head->dir_date = head->dir_date;
	while (head->name)
	{
		if (ft_strcmp(path, head->path) != 0)
		{
			max_head->next = init_head();
			max_head = max_head->next;
			free(path);
			path = ft_strdup(head->path);
			tmp->next = init_element();
			max_head->dir_path = ft_strdup(path);
			max_head->dir_info = head;
			max_head->dir_date = head->dir_date;
		}
		tmp = head;
		set_max(head, max_head);
		head = head->next;
	}
	free(path);
	max_head->next = init_head();
}

void		this(t_flags *flags, t_max *max_head, t_dir_info *head)
{
	t_dir_info *tmp;

	tmp = NULL;
	bring_me_max_t_r(head, max_head, tmp);
	pls_mercy(max_head, flags);
}
