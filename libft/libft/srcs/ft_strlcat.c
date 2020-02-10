/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <heikki-seta@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:16:01 by vtran             #+#    #+#             */
/*   Updated: 2019/10/18 19:02:10 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	slen;
	size_t	ret;

	len = ft_strlen((const char *)dst);
	slen = ft_strlen(src);
	if (size == 0)
		return (slen);
	if (len >= size)
		return (size + slen);
	ret = len + slen;
	while (len < size - 1 && *src)
		dst[len++] = *src++;
	dst[len] = '\0';
	return (ret);
}
