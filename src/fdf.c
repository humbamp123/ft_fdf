/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:21:27 by apineda           #+#    #+#             */
/*   Updated: 2017/05/19 14:46:31 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int					ft_key(int keycode, void *param)
{
	ERR1(keycode == 53, exit(1), 0);
	return (0);
}

int					exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

static	int			ft_read_file(t_map *map, char *arg)
{
	char		**array;
	char		*str;
	t_points	*list;
	int			fd;

	str = NULL;
	map->y_cnt = 1;
	map->cnt = 0;
	ERR((fd = open(arg, O_RDONLY)) < 0, -1);
	map->t = (t_points *)ft_memalloc(sizeof(t_points) * map->mrow * map->mcol);
	map->max = map->mrow > map->mcol ? map->mrow : map->mcol;
	map->incr = 1200 / (map->max + 10);
	map->size = 200 + map->incr * (map->max + 10);
	while (get_next_line(fd, &str) > 0)
	{
		ERR((array = ft_strsplit(str, ' ')) == NULL, -1);
		ft_insert_row(map, list, array);
		map->y_cnt++;
		ft_arraydel(array);
		ft_strdel(&str);
	}
	return (0);
}

static	int			ft_check_file(t_map *map, int fd)
{
	char		**array;
	char		*str;

	str = NULL;
	while (get_next_line(fd, &str) > 0)
	{
		ERR1((array = ft_strsplit(str, ' ')) == NULL || !*array,
			ft_arraydel(array), -1);
		if (map->mcol == 0)
		{
			ERR1((map->mcol = ft_col_check(array, map->mcol)) == -1,
				ft_strdel(&str), -1);
		}
		else
			ERR2((ft_col_check(array, map->mcol)) < 0, ft_arraydel(array),
				ft_strdel(&str), -1);
		map->mrow++;
		ft_arraydel(array);
		ft_strdel(&str);
	}
	return (0);
}

int					main(int argc, char **argv)
{
	t_map	*map;
	char	*str;
	int		fd;
	int		i;

	if (argc == 2 && (fd = open(argv[1], O_RDONLY)) >= 0)
	{
		ERW((str = ft_strstr(argv[1], ".fdf")) == 0 || ft_isalnum(str[4]), -1,
			"Filename Error");
		ft_bzero(&map, sizeof(map));
		map = (t_map *)ft_memalloc(sizeof(t_map));
		ERW1(ft_check_file(map, fd) == -1 || !map->mcol, free(map), -1,
			"File Format Error");
		ERW1(ft_read_file(map, argv[1]) == -1, free(map), -1, "Read Error");
		ft_put_map(map);
		ERR4(map, free(map->t), free(map->win), free(map->mlx), free(map), 0);
		close(fd);
	}
	else
		ft_printf("usage ./fdf <map.fdf>\n");
	return (0);
}
