/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:35:26 by lnqabash          #+#    #+#             */
/*   Updated: 2018/08/25 10:24:58 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zinnout(int keycode, t_vm *key)
{
	if (keycode == 69 && key->sx * 2 <= 500 && key->sy * 2 <= 500)
	{
		mlx_clear_window(key->mlx, key->win);
		key->sx *= 2;
		key->sy *= 2;
		key->z *= 2;
		sketch(key);
	}
	if (keycode == 78 && key->sx * 0.5 >= 1 && key->sy * 0.5 >= 1 &&
			(-key->z * 0.5 >= 1 || key->z * 0.5 >= 1))
	{
		mlx_clear_window(key->mlx, key->win);
		key->sx *= 0.5;
		key->sy *= 0.5;
		key->z *= 0.5;
		sketch(key);
	}
}

int		esc(void)
{
	exit(0);
	return (0);
}

void	cal(int keycode, t_vm *key)
{
	if ((keycode >= 123 && keycode <= 126) || keycode == 32)
	{
		mlx_clear_window(key->mlx, key->win);
		key->dx -= (keycode == 123) ? 10 : 0;
		key->dy -= (keycode == 126) ? 10 : 0;
		key->dx += (keycode == 124) ? 10 : 0;
		key->dy += (keycode == 125) ? 10 : 0;
		if (keycode == 32)
			key->origin = 0;
		sketch(key);
	}
}

int		keyevent(int keycode, t_vm *key)
{
	if (keycode == 53)
		esc();
	if (keycode == 42)
	{
		mlx_clear_window(key->mlx, key->win);
		key->z++;
		sketch(key);
	}
	if (keycode == 75)
	{
		mlx_clear_window(key->mlx, key->win);
		key->z--;
		sketch(key);
	}
	if (keycode == 11)
	{
		mlx_clear_window(key->mlx, key->win);
		key->color = 0x000000FF;
		sketch(key);
	}
	zinnout(keycode, key);
	cal(keycode, key);
	return (0);
}

void	mlx(t_vm *key)
{
	key->origin = 0;
	key->mlx = mlx_init();
	key->win = mlx_new_window(key->mlx, WIDTH, HEIGHT, "Fdf");
	sketch(key);
	mlx_key_hook(key->win, keyevent, key);
	mlx_hook(key->win, 17, (1L << 17), esc, key);
	mlx_loop(key->mlx);
}
