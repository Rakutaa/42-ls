/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:11:51 by vtran             #+#    #+#             */
/*   Updated: 2020/02/10 11:57:11 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	usage(void)
{
	ft_printf("Usage: ft_ls [-lRa] <dirname>\n");
	exit(0);
}

void		handle_error(const char *str)
{
	int errv;

	errv = errno;
	if (errv == ENOENT)
		ft_printf("ft_ls: %s: No such file or directory\n", str);
	if (errv == EACCES)
		ft_printf("ft_ls: %s: permission denied\n", str);
}

void		checkif_eaccess(const char *str)
{
	DIR *dirri;

	dirri = opendir(str);
	if (dirri != NULL)
	{
		ft_printf("%s:\n", str);
		closedir(dirri);
	}
}

void		print_flags(t_flags *f)
{
	if (f->flag_invalid)
		usage();
}
