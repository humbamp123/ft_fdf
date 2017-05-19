/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:22:02 by apineda           #+#    #+#             */
/*   Updated: 2017/05/19 14:15:13 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "mlx.h"
# include "libft.h"
# include <math.h>

typedef struct		s_points
{
	float			x;
	float			y;
	float			z;
	float			rawz;
	int				color;
}					t_points;

typedef struct		s_line
{
	float			adj;
	float			offset;
	float			thresh;
	float			rise;
	float			run;
	float			slope;
	float			delta;
	float			angx;
	float			angy;
	float			angz;
	float			ang;
	float			tmp;
	float			scale;
	float			printx;
	float			printy;
	float			printz;
	int				color;
}					t_line;

typedef	struct		s_map
{
	void			*win;
	void			*mlx;
	int				mcol;
	int				mrow;
	int				max;
	int				incr;
	int				size;
	int				x_cnt;
	int				y_cnt;
	int				cnt;
	t_points		*t;
}					t_map;

int					ft_key(int keycode, void *param);
int					exit_x(void *par);
int					ft_put_map(t_map *map);
int					ft_insert_row(t_map *map, t_points *list, char **array);
int					ft_col_check(char **ary, int cols);
void				ft_put_xdrive(t_map map, t_line *line);
void				ft_put_ydrive(t_map map, t_line *line);
void				ft_vert_line(t_map map, t_line *line, t_points pt1,
									t_points pt2);
void				ft_xdrive(t_map *map, t_line *line, t_points pt1,
									t_points pt2);
void				ft_ydrive(t_map *map, t_line *line, t_points pt1,
									t_points pt2);
void				ft_swap_ints(t_line *line, t_points *v1, t_points *v2);
int					ft_put_line_type(t_map *map, t_line *line);

#endif
