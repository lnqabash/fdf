/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:33:08 by lnqabash          #+#    #+#             */
/*   Updated: 2018/08/25 10:31:37 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# define WIDTH 1100
# define HEIGHT 750

typedef struct		s_vm
{
	int				z;
	int				fd;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				limit;
	int				**map;
	int				origin;
	int				nneka;
	char			*scan;
	void			*mlx;
	void			*win;
	unsigned long	color;
}					t_vm;

void				sketch(t_vm *draw);
void				sketch_limit(t_vm *draw, int x, int y);
void				check_env(t_vm *draw);
void				layout(t_vm *draw, int *tabxy, int x, int y);
void				mlx(t_vm *key);
int					keyevent(int keycode, t_vm *key);
void				cal(int keycode, t_vm *key);
int					esc(void);
void				zin(int keycode, t_vm *key);
void				zout(int keycode, t_vm *key);
void				fdf(t_vm *parse);
int					valu(int x, int y, int z);
int					inferr(t_vm *parse);
int					get_limit(t_vm *parse);
int					tab_axes(t_vm *parse, char *line);
int					spect_limit(char *str, int j, int contra);

#endif
