/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:06:07 by apineda           #+#    #+#             */
/*   Updated: 2017/05/19 14:14:55 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void				ft_swap_ints(t_line *line, t_points *v1, t_points *v2)
{
	if (line->slope <= 1 && line->slope >= -1)
	{
		if (v2->x < v1->x)
		{
			line->tmp = v1->x;
			line->printx = v2->x;
			line->printy = v2->y;
			return ;
		}
		line->printy = v1->y;
		line->printx = v1->x;
		line->tmp = v2->x;
		return ;
	}
	if (v2->y < v1->y)
	{
		line->tmp = v1->y;
		line->printy = v2->y;
		line->printx = v2->x;
		return ;
	}
	line->printy = v1->y;
	line->printx = v1->x;
	line->tmp = v2->y;
}

static	int			ft_put_line(t_map *map, t_line *line, t_points pt1,
								t_points pt2)
{
	line->rise = pt2.y - pt1.y;
	line->run = pt2.x - pt1.x;
	ERR1(line->run == 0, ft_vert_line(*map, line, pt1, pt2), 0);
	line->slope = line->rise / line->run;
	line->adj = line->slope >= 0 ? 1 : -1;
	if (line->slope <= 1 && line->slope >= -1)
		ft_xdrive(map, line, pt1, pt2);
	else
		ft_ydrive(map, line, pt1, pt2);
	return (0);
}

int					ft_put_line_type(t_map *map, t_line *line)
{
	t_points	pt1;
	t_points	pt2;
	t_points	pt3;
	int			i;

	i = 0;
	while (i < map->mrow * map->mcol)
	{
		line->offset = 0;
		line->thresh = 0.5;
		pt1 = (map->t[i]);
		if ((i + 1) % map->mcol != 0)
		{
			pt2 = (map->t[i + 1]);
			ft_put_line(map, line, pt1, pt2);
		}
		if (i + map->mcol < map->mrow * map->mcol)
		{
			pt3 = (map->t[i + map->mcol]);
			ft_put_line(map, line, pt1, pt3);
		}
		i++;
	}
	return (0);
}
