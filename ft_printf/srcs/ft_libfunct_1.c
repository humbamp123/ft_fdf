/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libfunct_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:28:40 by apineda           #+#    #+#             */
/*   Updated: 2017/03/09 21:29:04 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n--)
		*str++ = 0;
}

char	*ft_strnew(size_t size)
{
	char	*str;

	str = NULL;
	if (!(str = malloc(size + 1)))
		return (NULL);
	if (size)
		ft_bzero(str, size + 1);
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cpy;
	char	*test;

	test = (char *)dst;
	cpy = (char *)src;
	while (n--)
	{
		*test = *cpy;
		test++;
		cpy++;
	}
	return (dst);
}

char	*ft_strcpy(char *dst, char const *src)
{
	int		len;

	len = ft_strlen(src);
	ft_memcpy(dst, src, len);
	dst[len] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	cpy = NULL;
	if ((cpy = ft_strnew(ft_strlen(s1))))
		cpy = ft_strcpy(cpy, s1);
	return (cpy);
}
