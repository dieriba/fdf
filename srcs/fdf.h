/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:33:45 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/16 20:52:26 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# define BETA  -0.785398
# define ALPHA  0.610865238

typedef struct t_cord	t_cord;
typedef struct t_data	t_data;
typedef struct t_img	t_img;
typedef struct t_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	t_data	*data;
}	t_img;

typedef struct t_cord
{
	int		x;
	int		y;
	int		z;
	float	dx;
	float	dy;
	int		color;
	t_data	*data;
}	t_cord;

typedef struct t_data
{
	int		tabrow;
	int		fd;
	float	dx;
	float	dy;
	float	alpha;
	float	beta;
	int		tablen;
	int		width;
	int		height;
	char	*maps;
	char	*img_addr;
	void	*mlx_ptr;
	void	*win_ptr;
	int		vr_move;
	int		hr_move;
	int		zoom;
	int		z_zoom;
	int		redraw;
	t_img	*image;
	t_cord	**points;
}	t_data;

void	init_mlx(t_data *data);
void	init(t_data *data);
void	print_struct(t_data *data);
void	parse_maps(t_data *data);
void	print_err_and_exit(t_data *data, char *str, int syserror);
void	set_image(t_data *data);
void	free_all(t_data *data);
void	free_tabs(t_data *data, char ****tabs, char **tab, int err);

int		actions_hooks(t_data *data);
int		ft_error(char *str, int code);
int		handle_keypress(int keysym, t_data *data);
int		find_max(int a, int b);
int		close_loop(t_data *info);
int		color(t_cord *a, t_cord *b);
#endif