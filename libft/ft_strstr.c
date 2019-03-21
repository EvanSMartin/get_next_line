/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ispirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:16:54 by ispirido          #+#    #+#             */
/*   Updated: 2018/03/16 16:17:31 by ispirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** locates the first occurrence of the null-terminated string needle in
** the null-terminated string haystack.
** If needle is an empty string, haystack is returned; if needle occurs
** nowhere in haystack, NULL is returned; otherwise a pointer to the
** first character of the first occurrence of needle is returned.
*/

char	*ft_strstr(const char *hay, const char *need)
{
	int len1;
	int len2;

	len1 = ft_strlen(hay);
	len2 = ft_strlen(need);
	if (!len2)
		return (char *)hay;
	while (len1 >= len2)
	{
		if (!memcmp(hay, need, len2))
			return (char *)hay;
		hay++;
		len1--;
	}
	return (NULL);
}
