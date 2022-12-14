#include "fdf.h"

int	handle_keypress(int keysym, t_data *data)
{
	ft_printf("Touche : %i\n", keysym);
	if (keysym == XK_Escape)
		mlx_loop_end(data -> mlx_ptr);
	if (keysym == 65362)
	{
		data -> zoom += 1;
		set_image(data);
	}
	return (0);
}

int	close_loop(t_data *info)
{
	return (mlx_loop_end(info -> mlx_ptr));
}
