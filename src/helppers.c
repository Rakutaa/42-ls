/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helppers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <vtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:32:46 by vtran             #+#    #+#             */
/*   Updated: 2020/02/08 14:34:55 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*find_group(gid_t gid)
{
	struct group	*grp;
	char			*group;

	grp = getgrgid(gid);
	if (grp == NULL)
		return (NULL);
	group = ft_strdup(grp->gr_name);
	return (group);
}

char			*find_user(uid_t uid)
{
	struct passwd	*pwd;
	char			*user;

	pwd = getpwuid(uid);
	if (pwd == NULL)
		return (NULL);
	user = ft_strdup(pwd->pw_name);
	return (user);
}

char			*path_join(char *str1, char *str2)
{
	char			*ret;
	int				i;

	i = ft_strlen(str1);
	if (str1[i - 1] != '/')
	{
		ret = ft_strjoin(str1, "/");
		ret = ft_strjoin_f(ret, ft_strdup(str2));
	}
	else
		ret = ft_strjoin(str1, str2);
	return (ret);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char			*ptr;
	int				index[2];

	if (!s1 || !s2)
		return (NULL);
	if (!(ptr = (char *)malloc(sizeof(char) * \
		(ft_strlen((char *)s1) + ft_strlen((char *)s2)) + 1)))
		return (NULL);
	index[0] = 0;
	index[1] = 0;
	while (s1[index[0]] != '\0')
	{
		ptr[index[1]] = s1[index[0]];
		index[1]++;
		index[0]++;
	}
	index[0] = 0;
	while (s2[index[0]] != '\0')
	{
		ptr[index[1]] = s2[index[0]];
		index[1]++;
		index[0]++;
	}
	ptr[index[1]] = '\0';
	return (ptr);
}

unsigned int	count_i_len(int nbr)
{
	unsigned int	i;

	i = 1;
	while (nbr / 10 > 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}
