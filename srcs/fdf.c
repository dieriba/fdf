#include "fdf.h"
















int	main(int argc, char **argv)
{
	t_data	info;
	if (argc < 2)
		ft_error("Usage : ./fdf maps\n", 1);
	info.maps = argv[1];
	init(&info);
	parse_maps(&info);
	print_err_and_exit(&info, NULL, 0);
	free_all(&info);
}