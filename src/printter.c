/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:04:22 by vtran             #+#    #+#             */
/*   Updated: 2020/02/08 15:24:30 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	move_and_return_path(t_max **max_head, t_dir_info **head,
			char **str, t_flags *flags)
{
	int				i;

	i = 0;
	*max_head = (*max_head)->next;
	free(*str);
	*str = ft_strdup((*head)->path);
	flags->flag_l ? ft_printf("\n") : ft_printf("\n\n");
	ft_printf("%s:\n", (*head)->path);
	if (flags->flag_l)
		ft_printf("total %d\n", (*max_head)->blocks);
	return (i);
}

void		print_magic(t_dir_info *head, t_max *max, t_flags *flags)
{
	char			time[13];

	if (!flags->flag_l)
		ft_printf("%-*s", max->name + 1, head->name);
	else
	{
		parse_time(head->time, time);
		ft_printf("%s %*d %-*s %*s %*d %s %s\n", head->rights, max->links + 1,
		head->st_nlink, max->user, head->st_uid, max->group + 1,
		head->st_gid, max->size + 1, head->size, time, head->name);
	}
}

/*
**printing logic all dir cases except trR
*/

void		print_dir_cap(t_dir_info *head, t_max *max, t_flags *flags,
			unsigned int i)
{
	char			*str;
	struct winsize	w;
	int				t_w;
	int				cols;
	t_dir_info		*tail;

	tail = ft_roll(head);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	t_w = w.ws_col;
	str = ft_strdup(head->path);
	flags->flag_l ? ft_printf("total %d\n", max->blocks) : 0;
	while (head != tail)
	{
		cols = t_w / (max->name + 1) > 0 ? t_w / (max->name + 1) : 1;
		if (i % cols == 0 && i != 0 && !flags->flag_l && i != max->files)
			ft_putchar('\n');
		if (ft_strcmp(head->path, str) != 0 && max->next)
			i = move_and_return_path(&max, &head, &str, flags);
		print_magic(head, max, flags);
		head = head->next;
		i++;
	}
	if (!flags->flag_l)
		ft_putchar('\n');
	free(str);
}
