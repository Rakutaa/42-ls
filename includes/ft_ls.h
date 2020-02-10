/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:42:10 by vtran             #+#    #+#             */
/*   Updated: 2020/02/08 17:17:06 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include "../libft/includes/ft_printf.h"
# include <pwd.h>
# include <grp.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <time.h>

typedef struct			s_flags
{
	int32_t				flag_cap;
	int32_t				flag_l;
	int32_t				flag_a;
	int32_t				flag_r;
	int32_t				flag_t;
	int32_t				flag_invalid;
}						t_flags;

typedef struct			s_max
{
	unsigned int		links;
	unsigned int		user;
	unsigned int		group;
	unsigned int		size;
	unsigned int		name;
	unsigned int		blocks;
	unsigned int		files;
	char				*dir_path;
	unsigned int		dir_date;
	struct s_dir_info	*dir_info;
	struct s_max		*next;
}						t_max;

typedef struct			s_dir_info
{
	char				*name;
	mode_t				st_mode;
	nlink_t				st_nlink;
	char				*st_uid;
	char				*st_gid;
	off_t				size;
	time_t				time;
	char				*rights;
	blkcnt_t			blocks;
	char				*prev_path;
	char				*path;
	char				*full_path;
	time_t				dir_date;
	struct s_dir_info	*next;
}						t_dir_info;

/*
**utils
*/

t_flags					*parse_args(int *argc, char **args[]);
t_flags					*init_flags();
void					handle_error(const char *str);
void					checkif_eaccess(const char *str);
void					print_flags(t_flags *f);

/*
** File type & access rights
*/

void					print_rights(struct stat file);
void					set_rights(mode_t mode, char *str);

/*
** Directory management
*/

void					get_file_type(struct stat rights, char *str);
void					process_dir(DIR *pdir, t_flags *flags);
t_dir_info				*ft_filee(char *pth, t_dir_info *lst,
						t_flags *flgs, char *prv);

/*
** Lists management
*/

t_dir_info				*init_element();
t_max					*init_head();
t_dir_info				*ft_roll(t_dir_info *list);
void					bring_me_max(t_dir_info	*head, t_max *max_head);

/*
**sortters
*/

void					s_r_t_sort(t_max **start);

void					sort_ascii_params(char **v);
void					sort_r_params(char **v);
void					sort_params_if_t(char **d);
void					sort_params_if_t_r(char **d);

void					t_sort(t_dir_info **start, int swapped);
t_dir_info				*r_t_sort(t_dir_info **start, int swapped);
t_dir_info				*r_t_s_sort(t_dir_info **start);
void					ascii_sort(t_dir_info **start);
void					r_ascii_sort(t_dir_info **start);

void					swap(t_dir_info **b, t_dir_info **c,
						t_dir_info **n, t_dir_info **h);
void					set_start(t_dir_info **b, t_dir_info **c,
						t_dir_info **n, t_dir_info *s);
void					move_one(t_dir_info **b, t_dir_info **c,
						t_dir_info **n);

/*
**free
*/

void					free_list_head(t_dir_info *head, t_max *max);
void					free_list_s(t_dir_info *head);
void					free_head(t_dir_info *head);
void					free_list(t_dir_info *head);
void					free_max(t_max *max);
void					free_list_elem(t_dir_info *head);

/*
**printers
*/

void					this(t_flags *flags, t_max *max_head, t_dir_info *head);

void					that(t_flags *flags, t_max *max_head,
						t_dir_info *head, const char *path);
void					sort(t_dir_info **head, t_flags *flags);
void					print_dir_cap(t_dir_info *head, t_max *max_head,
						t_flags *flags, unsigned int i);
void					print_magic(t_dir_info	*head,
						t_max *max_head, t_flags *flags);

void					check_if_file(char **v, int j,
						char **d, t_flags *flags);

/*
**filesortters
*/

void					mini_t_r_sort(t_dir_info **head);
void					mini_t_sort(t_dir_info **head);
void					mini_ascii_sort(t_dir_info **head);
void					mini_r_ascii_sort(t_dir_info **head);

/*
**setters
*/

void					parse_time(time_t time_s, char *arr);
void					set_max(t_dir_info	*head, t_max *max_head);
char					*set_name(char *name, char *full_path);
void					set_list(t_dir_info *list, char *path,
						const char *name);
void					put_dir_date(t_dir_info *head);

/*
**helpers
*/

char					*ft_strjoin(char const *s1, char const *s2);
char					*path_join(char *str1, char *str2);
char					*find_user(uid_t uid);
char					*find_group(gid_t gid);
unsigned int			count_i_len(int nbr);

#endif
