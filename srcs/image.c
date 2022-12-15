/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:31:11 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/15 14:56:53 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	find_index(int x, int y, t_img *image)
{
	return (image -> line_len * y + x * (image -> bpp / 8));
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	x += img -> data -> hr_move;
	y += img -> data -> vr_move;
	if ((x < 0) || (x > img -> data -> width - 1)
		|| (y < 0) || (y > img -> data -> height - 1))
		return ;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	isometric(t_img *image, t_cord *a, t_cord *b)
{
	float	adx;
	float	ady;
	float	bdx;
	float	bdy;

	a -> dx = (a -> x - (int)(image -> data -> tablen / 2))
		* (image -> data -> zoom);
	a -> dy = (a -> y - (int)(image -> data -> tabrow / 2))
		* (image -> data -> zoom);
	b -> dy = (b -> y - (int)(image -> data -> tabrow / 2))
		* (image -> data -> zoom);
	b -> dx = (b -> x - (int)(image -> data -> tablen / 2))
		* (image -> data -> zoom);
	adx = a -> dx;
	bdx = b -> dx;
	ady = a -> dy;
	bdy = b -> dy;
	a -> dx = sin(a -> data -> beta) * ady + cos(a -> data -> beta) * adx;
	b -> dx = sin(a -> data -> beta) * bdy + cos(a -> data -> beta) * bdx;
	a -> dy = cos(a -> data -> alpha)
		* (cos(a -> data -> beta) * ady - sin(a -> data -> beta)
			* adx) - sin(a -> data -> alpha) * (a -> z * a -> data -> z_zoom);
	b -> dy = cos(a -> data -> alpha)
		* (cos(a -> data -> beta) * bdy - sin(a -> data -> beta)
			* bdx) - sin(a -> data -> alpha) * (b -> z * b -> data -> z_zoom);
}

void	draw_line(t_img *image, t_cord *a, t_cord *b)
{
	float	dy;
	float	dx;
	int		max;
	int		i;

	i = -1;
	isometric(image, a, b);
	dy = (b -> dy) - (a -> dy);
	dx = (b -> dx) - (a -> dx);
	max = find_max(fabs(dy), fabs(dx));
	dy /= max;
	dx /= max;
	while (++i < max)
	{
		img_pix_put(image, a -> dx, a -> dy, color(a, b));
		a -> dx += dx;
		a -> dy += dy;
	}
}

void	set_image(t_data *data)
{
	ssize_t	i;
	ssize_t	j;

	j = -1;
	i = -1;
	while (data -> points[++i])
	{
		while (++j < data -> tablen)
		{
			if (j < data -> tablen - 1)
				draw_line(data -> image, &data -> points[i][j],
					&data -> points[i][j + 1]);
			if (data -> points[i + 1])
				draw_line(data -> image, &data -> points[i][j],
					&data -> points[i + 1][j]);
		}
		j = -1;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->image -> mlx_img, 0, 0);
}
