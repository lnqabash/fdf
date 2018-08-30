/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:31:18 by lnqabash          #+#    #+#             */
/*   Updated: 2018/08/25 09:58:57 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_draw(t_vm *style)
{
	if (style->origin == 0)
	{
		style->z = -5;
		style->dx = WIDTH * 0.5;
		style->dy = 20;
		style->sx = (WIDTH * 0.5) / (style->nneka - 1);
		style->sy = (HEIGHT * 0.4) / (style->limit - 1);
		style->color = 0x00FFFFFF;
	}
	style->origin++;
}

void	sketch_limit(t_vm *motif, int x, int y)
{
	int		axesxy[2];

	axesxy[0] = motif->dx + (x - y);
	axesxy[1] = motif->dy + motif->map[y / motif->sy][x / motif->sx] * motif->z
		+ x + y;
	if (x / motif->sx < motif->nneka - 1 && y / motif->sy < motif->limit)
		layout(motif, axesxy, motif->dx + ((x + motif->sx) - y),
		motif->dy + motif->map[y / motif->sy][x / motif->sx + 1] * motif->z +
		(x + motif->sx) + y);
	if (y / motif->sy < motif->limit - 1 && x / motif->sx < motif->nneka)
		layout(motif, axesxy, motif->dx + (x - (y + motif->sy)),
		motif->dy + motif->map[y / motif->sy + 1][x / motif->sx] * motif->z +
		x + (y + motif->sy));
}

void	layout(t_vm *sketch, int *axesxy, int x, int y)
{
	int		ax;
	int		ay;
	int		axesx[2];
	int		axesy[2];
	int		frame[2];

	ax = axesxy[0];
	ay = axesxy[1];
	axesx[0] = abs(x - ax);
	axesx[1] = ax < x ? 1 : -1;
	axesy[0] = abs(y - ay);
	axesy[1] = ay < y ? 1 : -1;
	frame[0] = (axesx[0] > axesy[0] ? axesx[0] : -axesy[0]) / 2;
	while (ax != x || ay != y)
	{
		mlx_pixel_put(sketch->mlx, sketch->win, ax, ay, sketch->color);
		frame[1] = frame[0];
		frame[1] > -axesx[0] ? frame[0] -= axesy[0] : 1 == 1;
		frame[1] > -axesx[0] ? ax += axesx[1] : 1 == 1;
		frame[1] < axesy[0] ? frame[0] += axesx[0] : 1 == 1;
		frame[1] < axesy[0] ? ay += axesy[1] : 1 == 1;
	}
}

void	sketch(t_vm *sketch)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	check_draw(sketch);
	while (x / sketch->sx < sketch->nneka || y / sketch->sy < sketch->limit - 1)
	{
		if (x / sketch->sx == sketch->nneka)
		{
			x = 0;
			y += sketch->sy;
		}
		sketch_limit(sketch, x, y);
		x += sketch->sx;
	}
}
