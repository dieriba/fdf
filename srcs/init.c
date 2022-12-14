#include "fdf.h"


void	init_mlx(t_data* data)
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
	data -> points = NULL;
	data -> zoom = 2;
}