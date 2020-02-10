/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:38:29 by vtran             #+#    #+#             */
/*   Updated: 2020/02/10 11:55:33 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir_info		*ft_filee(char *path, t_dir_info *list, t_flags *flags,
				char *paths)
{
	struct dirent	*pdirent;
	DIR				*pdir;

	pdir = opendir(path);
	if (pdir == NULL)
	{
		handle_error(path);
		return (list);
	}
	while ((pdirent = readdir(pdir)))
	{
		if (pdirent->d_name[0] == '.' && !flags->flag_a)
			continue;
		set_list(list, path, pdirent->d_name);
		list->prev_path = ft_strdup(paths);
		list->name = (list->rights[0]) == 'l' && flags->flag_l ?
		set_name(pdirent->d_name, list->full_path) : ft_strdup(pdirent->d_name);
		list = list->next;
	}
	closedir(pdir);
	return (list);
}

static void		rec_wrapper(const char *path, t_flags *flags)
{
	t_dir_info		*head;
	t_dir_info		*tmp;
	t_dir_info		*tail;
	t_max			*max_head;

	head = init_element();
	tail = ft_filee((char *)path, head, flags, (char*)path);
	if (!head->name)
	{
		free(head);
		return ;
	}
	max_head = init_head();
	sort(&head, flags);
	tmp = head;
	while (tmp && tmp->name && flags->flag_cap)
	{
		if (S_ISDIR(tmp->st_mode) &&
		(ft_strcmp(tmp->name, "..") != 0 && ft_strcmp(tmp->name, ".") != 0))
			tail = ft_filee(tmp->full_path, ft_roll(tail), flags, tmp->path);
		tmp = tmp->next;
	}
	flags->flag_t ? put_dir_date(head) : head;
	!(flags->flag_r && flags->flag_cap && flags->flag_t) ?
	that(flags, max_head, head, path) : this(flags, max_head, head);
}

int				main(int c, char *v[])
{
	t_flags			*flags;
	int				i;
	char			*d[c];

	i = -1;
	while (++i < c)
		d[i] = NULL;
	flags = parse_args(&c, &v);
	print_flags(flags);
	flags->flag_r ? sort_r_params(v) : sort_ascii_params(v);
	c == 0 ? rec_wrapper(".", flags) : NULL;
	i = 0;
	if (i < c)
		check_if_file(v, -1, d, flags);
	if (flags->flag_t)
		flags->flag_r ? sort_params_if_t_r(d) : sort_params_if_t(d);
	while (d[i])
	{
		if (i > 0 || (d[c - 1] == NULL && v[c - 1] != NULL))
			checkif_eaccess((const char*)d[i]);
		rec_wrapper(d[i++], flags);
		if (d[i] != NULL)
			ft_printf("\n");
	}
	free(flags);
}
