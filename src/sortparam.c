/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortparam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:57:44 by vtran             #+#    #+#             */
/*   Updated: 2020/02/10 11:56:42 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_ascii_params(char **v)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (v[0] == NULL)
		return ;
	while (v[i + 1])
	{
		j = 1 + i;
		if (ft_strcmp(v[i], v[j]) > 0)
		{
			tmp = v[i];
			v[i] = v[j];
			v[j] = tmp;
			i = -1;
		}
		i++;
	}
}

void	sort_r_params(char **v)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (v[0] == NULL)
		return ;
	while (v[i + 1])
	{
		j = 1 + i;
		if (ft_strcmp(v[i], v[j]) < 0)
		{
			tmp = v[i];
			v[i] = v[j];
			v[j] = tmp;
			i = -1;
		}
		i++;
	}
}

/*
**sorting directory params with t
*/

void	sort_params_if_t(char **d)
{
	int			i;
	struct stat	file_info;
	struct stat	file_info2;
	char		*str;

	i = 0;
	while (d[i + 1])
	{
		lstat(d[i], &file_info);
		lstat(d[i + 1], &file_info2);
		if (file_info.st_mtime < file_info2.st_mtime)
		{
			str = d[i];
			d[i] = d[i + 1];
			d[i + 1] = str;
			i = -1;
		}
		i++;
	}
}

/*
**sorting directory params with -tr
*/

void	sort_params_if_t_r(char **d)
{
	int			i;
	struct stat	file_info;
	struct stat	file_info2;
	char		*str;

	i = 0;
	while (d[i + 1])
	{
		lstat(d[i], &file_info);
		lstat(d[i + 1], &file_info2);
		if (file_info.st_mtime > file_info2.st_mtime)
		{
			str = d[i];
			d[i] = d[i + 1];
			d[i + 1] = str;
			i = -1;
		}
		i++;
	}
}
