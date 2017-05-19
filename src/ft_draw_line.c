/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:00:29 by apineda           #+#    #+#             */
/*   Updated: 2017/05/19 14:14:12 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void				ft_put_xdrive(t_map map, t_line *line)
{
	mlx_pixel_put(map.mlx, map.win, line->printx, line->printy, line->color);
	line->offset += line->delta;
	if (line->offset >= line->thresh)
	{
		line->printy += line->adj;
		line->thresh += 1.0;
	}
	line->printx++;
}

void				ft_put_ydrive(t_map map, t_line *line)
{
	mlx_pixel_put(map.mlx, map.win, line->printx, line->printy, line->color);
	line->offset += line->delta;
	if (line->offset >= line->thresh)
	{
		line->printx += line->adj;
		line->thresh += 1.0;
	}
	line->printy++;
}

void				ft_vert_line(t_map map, t_line *line, t_points pt1,
									t_points pt2)
{
	line->slope = 2;
	ft_swap_ints(line, &pt1, &pt2);
	line->color = pt1.rawz < pt2.rawz ? pt1.color : pt2.color;
	while (line->printy < line->tmp + 1)
		mlx_pixel_put(map.mlx, map.win, line->printx, line->printy++,
						line->color);
}

void				ft_xdrive(t_map *map, t_line *line, t_points pt1,
									t_points pt2)
{
	line->delta = fabsf(line->slope);
	ft_swap_ints(line, &pt1, &pt2);
	line->color = pt1.rawz < pt2.rawz ? pt1.color : pt2.color;
	while (line->printx < line->tmp + 1)
		ft_put_xdrive(*map, line);
}

void				ft_ydrive(t_map *map, t_line *line, t_points pt1,
									t_points pt2)
{
	line->delta = fabsf(line->run / line->rise);
	ft_swap_ints(line, &pt1, &pt2);
	line->color = pt1.rawz < pt2.rawz ? pt1.color : pt2.color;
	while (line->printy < line->tmp + 1)
		ft_put_ydrive(*map, line);
}
