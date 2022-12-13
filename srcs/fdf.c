#include "fdf.h"















int	main(int argc, char **argv)
{
	t_data	info;
	t_img	image;

	if (argc < 2)
		ft_error("Usage : ./fdf maps\n", 1);
	init(&info);
	info.image = &image;
	info.maps = argv[1];
	parse_maps(&info);
	init_mlx(&info);
	image.data = &info;
	mlx_hook(info.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &info);
	image.mlx_img = mlx_new_image(info.mlx_ptr, info.width, info.height);
	info.image -> addr = mlx_get_data_addr(info.image -> mlx_img, &info.image -> bpp,
	&info.image -> line_len, &info.image -> endian);
	set_image(&info);
	mlx_loop(info.mlx_ptr);
	free_all(&info);
}