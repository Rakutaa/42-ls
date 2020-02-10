/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:50:15 by vtran             #+#    #+#             */
/*   Updated: 2020/02/10 11:45:17 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_dir_info	*do_files(t_dir_info *head,
					char *name, t_flags *flags)
{
	set_list(head, ".", name);
	head->name = (head->rights[0]) == 'l' && flags->flag_l ?
	set_name(name, name) : ft_strdup(name);
	head = head->next;
	return (head);
}

static void			print_dir_f(t_dir_info *head, t_max *max_head,
					t_flags *flags, unsigned int i)
{
	struct winsize	w;
	int				term_width;
	int				cols;
	t_dir_info		*tail;

	tail = ft_roll(head);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	term_width = w.ws_col;
	while (head != tail)
	{
		cols = term_width / (max_head->name + 1) > 0 ? term_width /
		(max_head->name + 1) : 1;
		if (i % cols == 0 && i != 0 && !flags->flag_l && i != max_head->files)
			ft_putchar('\n');
		print_magic(head, max_head, flags);
		head = head->next;
		i++;
	}
}

/*
**app to print out files and makes nessesary sorts
*/

static void			print_files(t_dir_info *head, t_max *max,
					t_flags *flags, char *dir)
{
	bring_me_max(head, max);
	if (flags->flag_t)
		flags->flag_r ? mini_t_r_sort(&head) : mini_t_sort(&head);
	else
		flags->flag_r ? mini_r_ascii_sort(&head) : mini_ascii_sort(&head);
	print_dir_f(head, max, flags, 0);
	free_list_head(head, max);
	if (dir)
		ft_printf("\n");
	if (!flags->flag_l)
		ft_putchar('\n');
}

/*
**work out with files and put directories to d
*/

void				check_if_file(char **v, int j, char **d, t_flags *flags)
{
	struct stat	file_info;
	int			i;
	t_dir_info	*head;
	t_dir_info	*tmp;
	int			x;

	i = -1;
	head = init_element();
	tmp = head;
	while (v[++i])
	{
		x = lstat(v[i], &file_info);
		if (S_ISDIR(file_info.st_mode) && x == 0)
		{
			d[++j] = v[i];
		}
		else if (x == 0)
			tmp = do_files(tmp, v[i], flags);
		else
			handle_error(v[i]);
	}
	if (head->name)
		print_files(head, init_head(), flags, d[0]);
	else
		free(head);
}
