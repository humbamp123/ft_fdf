/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libfunct_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:42:22 by apineda           #+#    #+#             */
/*   Updated: 2017/05/05 17:56:28 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

size_t		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

void		*ft_memset(void *b, int c, size_t len)
{
	char	*cpy;

	cpy = b;
	while (len--)
	{
		*cpy = c;
		cpy++;
	}
	return (b);
}

void		ft_strdel(char **as)
{
	if (as)
	{
		ft_memdel((void *)as);
		as = NULL;
	}
}

char		*ft_strnstr(const char *big, const char *tiny, size_t len)
{
	int		iter[2];

	ft_bzero((void*)iter, sizeof(int) * 2);
	if (tiny[iter[0]] == '\0')
		return ((char *)big);
	while (big[iter[0]] != '\0' && len)
		if (big[iter[0]] == tiny[iter[1]])
		{
			if (tiny[iter[1] + 1] == '\0')
				return ((char *)&big[iter[0] - iter[1]]);
			iter[0]++;
			iter[1]++;
			len--;
		}
		else
		{
			if (iter[1] > 0)
				iter[0] = iter[0] - iter[1];
			if (iter[1] > 0)
				len = len + iter[1];
			iter[0]++;
			iter[1] = 0;
			len--;
		}
	return (0);
}
