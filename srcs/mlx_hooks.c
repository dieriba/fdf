/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:16:24 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/16 20:52:18 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	options(int keysym, t_data *data)
{
	if (keysym == 97)
		data -> alpha -= 1;
	if (keysym == 'h')
		data -> beta += 1;
	if (keysym == 'f')
		data -> beta -= 1;
	if (keysym == 'z')
		data -> z_zoom += 1;
	if (keysym == 'x')
		data -> z_zoom -= 1;
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_loop_end(data -> mlx_ptr);
	if (keysym == 113)
		data -> zoom += 1;
	if (keysym == 101)
		data -> zoom -= 1;
	if (keysym == 65364)
		data -> vr_move += 1;
	if (keysym == 65362)
		data -> vr_move -= 1;
	if (keysym == 65363)
		data -> hr_move += 1;
	if (keysym == 65361)
		data -> hr_move -= 1;
	if (keysym == 100)
		data -> alpha += 1;
	options(keysym, data);
	data -> redraw = 1;
	return (0);
}

int	actions_hooks(t_data *data)
{
	if (data -> redraw == 1)
	{
		mlx_destroy_image(data -> mlx_ptr, data -> image -> mlx_img);
		data -> image -> mlx_img = mlx_new_image(data -> mlx_ptr,
				data -> width, data -> height);
		data -> image -> addr = mlx_get_data_addr(data -> image -> mlx_img,
				&data -> image -> bpp,
				&data -> image -> line_len, &data
				-> image -> endian);
		set_image(data);
		data -> redraw = 0;
	}
	return (0);
}

int	close_loop(t_data *info)
{
	return (mlx_loop_end(info -> mlx_ptr));
}
