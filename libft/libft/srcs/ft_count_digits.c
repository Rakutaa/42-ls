/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:28:44 by vtran             #+#    #+#             */
/*   Updated: 2019/11/28 13:25:23 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_digits(uint64_t n, int base)
{
	if (n < (uint64_t)base)
		return (1);
	else
		return (ft_count_digits(n / base, base) + 1);
}
