/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:31:00 by vtran             #+#    #+#             */
/*   Updated: 2020/02/08 14:31:22 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_list_elem(t_dir_info *head)
{
	free(head->path);
	free(head->full_path);
	free(head->rights);
	free(head->st_gid);
	free(head->st_uid);
	free(head->prev_path);
	free(head->name);
}
