/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:48:05 by vtran             #+#    #+#             */
/*   Updated: 2020/02/08 14:48:07 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_file_type(struct stat rights, char *str)
{
	if (S_ISREG(rights.st_mode))
		str[0] = '-';
	else if (S_ISLNK(rights.st_mode))
		str[0] = 'l';
	else if (S_ISDIR(rights.st_mode))
		str[0] = 'd';
	else if (S_ISSOCK(rights.st_mode))
		str[0] = 's';
	else if (S_ISCHR(rights.st_mode))
		str[0] = 'c';
	else if (S_ISFIFO(rights.st_mode))
		str[0] = 'p';
	else if (S_ISBLK(rights.st_mode))
		str[0] = 'b';
}

void	set_rights(mode_t mode, char *str)
{
	str[0] = (mode & S_IRUSR) ? 'r' : '-';
	str[1] = (mode & S_IWUSR) ? 'w' : '-';
	str[2] = (mode & S_IXUSR) ? 'x' : '-';
	str[3] = (mode & S_IRGRP) ? 'r' : '-';
	str[4] = (mode & S_IWGRP) ? 'w' : '-';
	str[5] = (mode & S_IXGRP) ? 'x' : '-';
	str[6] = (mode & S_IROTH) ? 'r' : '-';
	str[7] = (mode & S_IWOTH) ? 'w' : '-';
	str[8] = (mode & S_IXOTH) ? 'x' : '-';
}
