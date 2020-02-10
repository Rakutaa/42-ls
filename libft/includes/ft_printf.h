/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:33:46 by vtran             #+#    #+#             */
/*   Updated: 2020/01/31 15:54:19 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

# define BLACK "\033[01;30m"
# define RED "\033[01;31m"
# define GREEN "\033[01;32m"
# define YELLOW "\033[01;33m"
# define BLUE "\033[01;34m"
# define MAGNETA "\033[01;35m"
# define CYAN "\033[01;36m"
# define WHITE "\033[01;37m"
# define NORMAL "\033[0;39m"

# define ABS(x) ((x) < 0) ? -(x) : (x)

# define CONVERSION "cspdiouxXfb"

# define F_HASH		(1 << 0)
# define F_ZERO		(1 << 1)
# define F_MINUS	(1 << 2)
# define F_SPACE	(1 << 3)
# define F_PLUS		(1 << 4)
# define F_CHAR		(1 << 5)
# define F_SHORT	(1 << 6)
# define F_LONG		(1 << 7)
# define F_LLONG	(1 << 8)
# define F_DOUBLE	(1 << 9)
# define F_DOT		(1 << 10)
# define F_PWILD	(1 << 11)
# define F_DWILD	(1 << 12)

typedef struct	s_print
{
	int			pad;
	char		*fmt;
	char		*buf;
	char		c;
	short		flags;
	int			ppad;
	int			len;
	va_list		ap;
}				t_print;

int				check_if_zeros(char *str);
int				ft_printf(const char *restrict format, ...);

void			wildcard(t_print **p);
void			append_buffer(t_print **p, char *append_this, int len);
void			parse_csp(t_print **p);
void			parse_diouxx(t_print **p);
void			parse_colors(t_print **p);
void			pointer(t_print **p);

char			*ft_memjoin(t_print **p, char *append_this, int len);

t_print			*parse_flags(t_print **p);

/*
** -------- STRING FUNCTIONS --------
*/

void			add_wstring(t_print **p);
void			add_wchar(t_print **p);
void			add_char(t_print **p);
void			add_string(t_print **p);
char			*str_to_upper(char *str);
/*
** -------- NUMBER FUNCTIONS --------
*/

int				if_symbols_move(t_print **p, char **srcs, char *str, int len);

char			*handle_signed(t_print **p);
char			*handle_unsigned(t_print **p);
char			*handle_double(t_print **p);
char			*ftoa(long double nb, int prec, t_print **pr);

char			*padding(t_print **p, char *pad_thai);
char			*padding_with_minus(t_print **p, int len, char *src);
char			*padding_with_dot(t_print **p, char *src);
char			*padding_no_flag(t_print **p, int len, char *src);

char			*precision(t_print **p, char *prec);
char			*ox_prefix(t_print **p, char *str);
char			*space(t_print **p, char *brownies);
char			*add_sign(char *str);
int				ft_count_digits_l(int64_t n, int base);

#endif
