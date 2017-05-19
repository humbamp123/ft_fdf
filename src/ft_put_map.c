/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 13:54:23 by apineda           #+#    #+#             */
/*   Updated: 2017/05/19 14:28:39 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static	void		ft_rotate(t_map *map, t_line *line, t_points *pt)
{
	float		z;
	float		x;
	float		y;

	z = pt->z * 5;
	x = pt->x;
	y = pt->y;
	pt->rawz = z;
	pt->color = z > 0 ? 0x0000FFFF : 0x00FFFFFF;
	pt->color = z < 0 ? 0x00FFFF00 : pt->color;
	y = round(y * cos(0.296706) - z * sin(0.296706));
	z = round(pt->y * sin(0.296706) + z * cos(0.296706));
	pt->y = y;
	x = round(x * cos(line->ang) - y * sin(line->ang) + (float)map->size / 2.0);
	pt->y = round(pt->x * sin(line->ang) + y * cos(line->ang) +
				(float)map->size / 2.0);
	pt->x = x;
	x = round(x * cos(.0523599) + z * sin(.0523599));
	pt->z = round(-pt->x * sin(.0523599) + z * cos(.0523599));
	pt->x = x;
}

static	void		ft_rotate_scale(t_map *map, t_line *line)
{
	t_points	*pt1;
	int			i;

	i = 0;
	while (i < map->mcol * map->mrow)
	{
		pt1 = &(map->t[i++]);
		ft_rotate(map, line, pt1);
	}
}

int					ft_col_check(char **ary, int cols)
{
	int		count_cols;
	int		i;

	i = 0;
	if (cols == 0)
	{
		while (ary[i])
		{
			cols++;
			i++;
		}
		return (cols);
	}
	else
	{
		count_cols = 0;
		while (ary[i])
		{
			count_cols++;
			i++;
		}
		if (cols != count_cols)
			return (-1);
	}
	return (0);
}

int					ft_insert_row(t_map *map, t_points *list, char **array)
{
	int		i;

	i = 0;
	map->x_cnt = 1;
	ERW(map->incr < 5, 0, "Error, map is too large");
	while (array[i])
	{
		list = &(map->t[map->cnt++]);
		list->x = ((float)map->x_cnt - (float)map->mcol / 2.0) * map->incr;
		list->y = ((float)map->y_cnt - (float)map->mrow / 2.0) * map->incr;
		list->z = (float)ft_atoi(array[i]);
		i++;
		map->x_cnt++;
	}
	return (0);
}

int					ft_put_map(t_map *map)
{
	t_line		*line;

	line = (t_line *)ft_memalloc(sizeof(t_line));
	line->ang = 0.785398;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->size, map->size, "fdf");
	ft_rotate_scale(map, line);
	ft_put_line_type(map, line);
	mlx_key_hook(map->win, ft_key, 0);
	mlx_hook(map->win, 17, 0, exit_x, 0);
	mlx_loop(map->mlx);
	return (0);
}
