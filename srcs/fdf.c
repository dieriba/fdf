#include "fdf.h"
















int	main(int argc, char **argv)
{
	t_data	info;
	if (argc < 2)
		ft_error("Usage : ./fdf maps\n", 1);
	info.maps = argv[1];
	parse_maps(&info);
}