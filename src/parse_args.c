/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:46:58 by vtran             #+#    #+#             */
/*   Updated: 2020/02/10 11:57:24 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flags		*init_flags(void)
{
	t_flags *flag_struct;

	if (!(flag_struct = (t_flags *)malloc(sizeof(*flag_struct))))
		return (NULL);
	flag_struct->flag_l = 0;
	flag_struct->flag_a = 0;
	flag_struct->flag_cap = 0;
	flag_struct->flag_r = 0;
	flag_struct->flag_t = 0;
	flag_struct->flag_invalid = 0;
	return (flag_struct);
}

static void	set_flag(char flag, t_flags *flag_struct)
{
	if (flag == 'a')
		flag_struct->flag_a = 1;
	else if (flag == 'R')
		flag_struct->flag_cap = 1;
	else if (flag == 'l')
		flag_struct->flag_l = 1;
	else if (flag == 't')
		flag_struct->flag_t = 1;
	else if (flag == 'r')
		flag_struct->flag_r = 1;
	else
		flag_struct->flag_invalid = 1;
}

static int	check_arg(char *arg, t_flags *flag_struct)
{
	int		i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == '-')
			i++;
		set_flag(arg[i], flag_struct);
		i++;
	}
	return (1);
}

t_flags		*parse_args(int *argc, char **args[])
{
	t_flags	*flags;

	flags = init_flags();
	if (!flags)
		exit(0);
	(*args) = &(*args)[1];
	(*argc)--;
	while (1)
	{
		if ((*args)[0] && (*args)[0][0] == '-' && (*args))
		{
			if (check_arg((*args)[0], flags))
			{
				if (*argc > 1)
					(*args) = &(*args)[1];
				else
					(*args)[0] = NULL;
				(*argc)--;
			}
		}
		else
			break ;
	}
	return (flags);
}
