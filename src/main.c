/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:21:27 by apineda           #+#    #+#             */
/*   Updated: 2017/05/08 19:33:33 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static	int	ft_key(int keycode, void *param)
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



int				main(int argc, char	**argv)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "fdf");
	mlx_pixel_put(mlx, win, 200, 200, 255);
	mlx_key_hook(win, ft_key, 0);
	mlx_hook(win, 17, 1L << 17, exit_x, 0);
	mlx_loop(mlx);

	return (0);
}