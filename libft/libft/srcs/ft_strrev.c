/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtran <heikki-seta@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:30:06 by vtran             #+#    #+#             */
/*   Updated: 2019/11/26 15:30:11 by vtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	*beg;
	char	*rev;
	char	*end;
	char	temp;

	beg = str;
	rev = str;
	end = str;
	while (*end)
		end++;
	end--;
	while (beg < end)
	{
		temp = *beg;
		*beg = *end;
		*end = temp;
		end--;
		beg++;
	}
	return (rev);
}
