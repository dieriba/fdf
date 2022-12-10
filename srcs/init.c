#include "fdf.h"

void	init(t_data *data)
{
	data -> maps = NULL;
	data -> tabrow = 0;
	data -> tablen = 0;
	data -> width = 0;
	data -> height = 0;
	data -> points = NULL;
}