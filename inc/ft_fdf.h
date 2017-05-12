/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:22:02 by apineda           #+#    #+#             */
/*   Updated: 2017/05/11 23:47:19 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "mlx.h"
# include "libft.h"

typedef struct		s_link
{
	int				*row;
	struct s_link	*next;
}					t_link;

typedef	struct		s_map
{
	void			*win;
	void			*mlx;
	int				x;
	int				y;
	int				col;
	t_link			*t;
}					t_map;

#endif