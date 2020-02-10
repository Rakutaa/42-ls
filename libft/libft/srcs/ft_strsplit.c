/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <heikki-seta@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:28:41 by vtran             #+#    #+#             */
/*   Updated: 2019/10/18 18:22:57 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	counter = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			counter++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (counter);
}

static size_t	ft_word_len(const char *s, char c)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (counter == 0 && s[i] == c)
			i++;
		else if (counter != 0 && s[i] == c)
			return (counter);
		else
		{
			counter++;
			i++;
		}
	}
	return (counter);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	j;
	size_t	i;
	size_t	len;
	size_t	words;
	char	**ret;

	i = 0;
	words = ft_words(s, c);
	if (!s || (!(ret = (char **)malloc(sizeof(char*) * (words + 1)))))
		return (NULL);
	while (i < words)
	{
		j = 0;
		len = ft_word_len(s, c);
		if (!(ret[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (*s == c)
			s++;
		while (j < len)
			ret[i][j++] = (char)*s++;
		ret[i][j] = '\0';
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
