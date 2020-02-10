/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:36:56 by vtran             #+#    #+#             */
/*   Updated: 2019/11/28 13:25:44 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_populate_string(char *r, int i, long long nb)
{
	while (nb >= 10)
	{
		r[i--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	r[i] = (char)(nb % 10 + 48);
	return (r);
}

char			*ft_itoa(long long nb)
{
	int			i;
	int			flag;
	int			len;
	char		*r;

	flag = 0;
	if (nb + 1 == -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (nb < 0)
	{
		nb *= -1;
		flag = 1;
	}
	len = ft_count_digits(nb, 10);
	if (!(r = (char *)malloc(sizeof(char) * (len + 1 + flag))))
		return (NULL);
	i = len - 1 + flag;
	if (flag)
		r[0] = '-';
	r = ft_populate_string(r, i, nb);
	r[len + flag] = '\0';
	return (r);
}
