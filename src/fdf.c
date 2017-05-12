/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:21:27 by apineda           #+#    #+#             */
/*   Updated: 2017/05/12 00:29:10 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static	int			ft_key(int keycode, void *param)
{
	ERR1(keycode == 53, exit(1), 0);
	// ERR1(keycode == 49, space, 0);
	// ERR1(keycode == 123, left, 0);
	// ERR1(keycode == 124, right, 0);
	// ERR1(keycode == 125, down, 0);
	// ERR1(keycode == 126, up, 0);
	return (0);
}

// static int	ft_mouse()
static	int			exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

static int			*ft_get_array_num(t_map *map, char **array)
{
	int		*ret;
	int		i;

	ret = (int *)ft_memalloc(sizeof(int) * map->col);
	i = 0;
	while (array[i])
	{
		ret[i] = ft_atoi(array[i]);
		printf("NUM = %d", ret[i]);
		i++;
	}
	printf("%d\n", i);
	ft_strdel(array);
	i = 0;
	while (ret[i])
	{
		printf("NUM %d = %d", i, ret[i]);
	}
	return (ret);
}

static	int			ft_col_check(char **ary, int cols)
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

static	int			ft_read_file(t_map *map, int fd)
{
	char	**array;
	char	*str;
	int		*ints;
	t_link	*list;

	list = map->t;
	str = ft_strnew(100);
	while (get_next_line(fd, &str) > 0)
	{
		ERR((array = ft_strsplit(str, ' ')) == NULL, -1);
		if (map->col == 0)
		{
			ERR((map->col = ft_col_check(array, map->col)) == -1, -1);
		}
		else
			ERR1((ft_col_check(array, map->col)) < 0, ft_arraydel(array), -1);
		ints = ft_get_array_num(map, array);
		// list->row = ft_get_array_num(map, array);
		// list = list->next;
		ft_strdel(&str);
	}
	return (0);
}

// static	int				ft_put_map(t_map *map)
// {


// }

int					main(int argc, char	**argv)
{
	t_map	map;
	int		fd;

	if (argc == 2 && (fd = open(argv[1], O_RDONLY)) >= 0)	
	{
		ft_bzero(&map, sizeof(map));
		ERW(ft_read_file(&map, fd) == -1, -1, "Read Error");
		// map.mlx = mlx_init();
		// map.win = mlx_new_window(map.mlx, 500, 500, "fdf");
		// // ft_put_map(map);
		// mlx_key_hook(map.win, ft_key, 0);
		// mlx_hook(map.win, 17, 1L << 17, exit_x, 0);
		// mlx_loop(map.mlx);
	}
	else
		ft_printf("it works, but your input doesn't");
	return (0);
}