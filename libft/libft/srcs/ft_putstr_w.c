/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_w.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:31:16 by vtran             #+#    #+#             */
/*   Updated: 2020/01/31 15:40:17 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_putstr_w(wchar_t *str)
{
	char	*ret;

	if (!str)
		return (NULL);
	ret = ft_putchar_w(*str);
	str++;
	while (*str)
	{
		ret = ft_strjoin_f(ret, ft_putchar_w(*str));
		str++;
	}
	return (ret);
}
