/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <heikki-seta@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:12:26 by vtran             #+#    #+#             */
/*   Updated: 2019/10/16 17:53:13 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	size;

	size = ft_strlen(s) + 1;
	if (!(ret = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ret = ft_memcpy(ret, s, size);
	return (ret);
}
