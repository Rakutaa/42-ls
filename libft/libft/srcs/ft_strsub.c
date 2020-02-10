/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:30:07 by vtran             #+#    #+#             */
/*   Updated: 2020/02/03 15:48:45 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char *s, unsigned int start, size_t len)
{
	char	*r;

	if (!s || !(r = ft_memalloc(len + 1)))
		return (NULL);
	r = ft_strncpy(r, (char *)&(s[start]), len);
	free(s);
	return (r);
}

char	*ft_strsub_s(char *s, unsigned int start, size_t len)
{
	char	*r;

	if (!s || !(r = ft_memalloc(len + 1)))
		return (NULL);
	r = ft_strncpy(r, (char *)&(s[start]), len);
	return (r);
}
