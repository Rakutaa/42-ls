/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <heikki-seta@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:26:47 by vtran             #+#    #+#             */
/*   Updated: 2019/10/16 17:57:23 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i != n)
	{
		j = 0;
		while (s1[i] == s2[j] && i != n && s1[i] != '\0')
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + (i - j));
		if (i == n)
			return (NULL);
		i++;
	}
	return (NULL);
}
