/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:22:32 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/15 15:56:11 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_data *data)
{
	data -> mlx_ptr = mlx_init();
	if (!data -> mlx_ptr)
		exit (EXIT_FAILURE);
	data -> win_ptr = mlx_new_window(data -> mlx_ptr, data -> width,
			data -> height, "Fdf");
	if (!data -> win_ptr)
		free_all(data);
}

void	init(t_data *data)
{
	data -> maps = NULL;
	data -> tabrow = 0;
	data -> tablen = 0;
	data -> width = 1920;
	data -> height = 1080;
	data -> hr_move = (data -> width / 2);
	data -> vr_move = (data -> height / 2);
	data -> points = NULL;
	data -> zoom = 20;
	data -> redraw = 0;
	data -> z_zoom = 1;
	data -> alpha = ALPHA;
	data -> beta = BETA;
	data -> mlx_ptr = NULL;
	data -> image = NULL;
}
