/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:08:02 by vtran             #+#    #+#             */
/*   Updated: 2020/02/08 17:10:31 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_list(t_dir_info *list, char *path,
		const char *name)
{
	char		*new;
	struct stat	file;

	list->path = strdup(path);
	new = path_join(path, (char*)name);
	lstat(new, &file);
	list->rights = ft_strnew(10);
	get_file_type(file, list->rights);
	set_rights(file.st_mode, &list->rights[1]);
	list->full_path = new;
	list->st_gid = find_group(file.st_gid);
	list->st_mode = file.st_mode;
	list->st_nlink = file.st_nlink;
	list->st_uid = find_user(file.st_uid);
	list->next = init_element();
	list->size = file.st_size;
	list->time = file.st_mtime;
	list->blocks = file.st_blocks;
}

char	*set_name(char *name, char *full_path)
{
	char	link[1025];
	int		ret;
	char	*lname;

	lname = ft_strjoin(name, " -> ");
	ret = readlink(full_path, link, 1024);
	link[ret] = '\0';
	lname = ft_strjoin_f(lname, ft_strdup(link));
	return (lname);
}

/*
**setting padding list content
*/

void	set_max(t_dir_info *head, t_max *max_head)
{
	max_head->name = max_head->name < ft_strlen(head->name) ?
	ft_strlen(head->name) : max_head->name;
	max_head->links = max_head->links < count_i_len((int)head->st_nlink) ?
	count_i_len((int)head->st_nlink) : max_head->links;
	max_head->group = max_head->group < ft_strlen(head->st_gid) ?
	ft_strlen(head->st_gid) : max_head->group;
	max_head->size = max_head->size < count_i_len((int)head->size) ?
	count_i_len((int)head->size) : max_head->size;
	max_head->user = max_head->user < ft_strlen(head->st_uid) ?
	ft_strlen(head->st_uid) : max_head->group;
	max_head->blocks = max_head->blocks + head->blocks;
	max_head->files = max_head->files + 1;
}

void	parse_time(time_t time_s, char *arr)
{
	time_t		curtime;
	char		current[5];
	char		file[5];

	time(&curtime);
	ft_memset(arr, 0, 13);
	ft_memset(current, 0, 5);
	ft_memset(file, 0, 5);
	ft_memcpy(current, &(ctime(&curtime)[ft_strlen(ctime(&curtime)) - 5]), 4);
	ft_memcpy(file, &(ctime(&time_s)[ft_strlen(ctime(&time_s)) - 5]), 4);
	if (ft_strcmp(current, file))
	{
		ft_strncpy(arr, &(ctime(&time_s)[4]), 7);
		arr[7] = ' ';
		ft_strcat(arr, file);
	}
	else
		ft_strncpy(arr, &(ctime(&time_s)[4]), 12);
}

/*
**when -t flag to have directory mdate in memory
*/

void	put_dir_date(t_dir_info *head)
{
	time_t		date;
	char		full_path[2000];
	t_dir_info	*tmp;

	while (head->name)
	{
		if (head->rights[0] == 'd')
		{
			tmp = head;
			date = head->time;
			ft_strcpy(full_path, tmp->full_path);
			if (!tmp->next->name)
				break ;
			tmp = tmp->next;
			while (ft_strcmp(tmp->path, full_path) && tmp->next->name)
				tmp = tmp->next;
			while (ft_strcmp(tmp->path, full_path) == 0 && tmp->next->name)
			{
				tmp->dir_date = date;
				tmp->next->name ? tmp = tmp->next : tmp;
			}
			ft_bzero(full_path, 2000);
		}
		head = head->next;
	}
}
