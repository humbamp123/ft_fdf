/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libfunct_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:29:36 by apineda           #+#    #+#             */
/*   Updated: 2017/04/03 16:35:19 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!len)
	{
		str = ft_strnew(len + 1);
		*str = '\0';
		return (str);
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (!s)
		return (NULL);
	if (str)
		ft_strncpy(str, &s[start], len);
	return (str);
}

int			ft_nbrlen(intmax_t num)
{
	int		flag;

	if (num == 0)
		return (1);
	flag = num < 0 ? 1 : 0;
	while (num != 0)
	{
		num = num / 10;
		++flag;
	}
	return (flag);
}

char		*ft_itoa(intmax_t nbr)
{
	char	*str;
	int		len;
	int		flag;
	int		end;

	len = ft_nbrlen(nbr);
	end = len;
	if (!(str = ft_strnew(len)))
		return (NULL);
	flag = nbr < 0 ? 1 : 0;
	nbr = flag ? -nbr : nbr;
	while (--len)
	{
		str[len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	str[len] = flag ? '-' : nbr % 10 + '0';
	str[end] = '\0';
	return (str);
}

static int	ft_nbrlen_base(uintmax_t num, short base)
{
	int		flag;

	if (num == 0)
		return (1);
	flag = 0;
	while (num != 0)
	{
		num = num / base;
		++flag;
	}
	return (flag);
}

char		*ft_itoa_base(uintmax_t nbr, short base)
{
	char	*str;
	int		len;
	int		end;

	len = ft_nbrlen_base(nbr, base);
	end = len;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (--len)
	{
		str[len] = HEX[nbr % base];
		nbr = nbr / base;
	}
	str[len] = HEX[nbr % base];
	str[end] = '\0';
	return (str);
}
