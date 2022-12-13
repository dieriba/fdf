#include "fdf.h"

# define COLOR(color) color ? 0xFF0000 : 0xFFFFFF 
# define ABS(x) (x < 0) ? -x : x
# define MAX(a,b) (a > b) ? a : b
int find_index(int x, int y, t_img *image)
{
    return (image -> line_len * y + x * (image -> bpp / 8));
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	isometric(t_cord *a, t_cord *b)
{
	a -> dx = (a -> dx - a -> dy) * cos(0.8);
	a -> dy = (a -> dx + a -> dy) * sin(0.8) - a -> z;
	b -> dx = (b -> dx - b -> dy) * cos(0.8);
	b -> dy = (b -> dx + b -> dy) * sin(0.8) - b -> z;
}

void	draw_line(t_img *image, t_cord *a, t_cord *b)
{
	float	dy;
	float	dx;
	int		max;

	a -> dx = a -> x * (image -> data -> zoom);
	a -> dy = a -> y * (image -> data -> zoom);
	b -> dy = b -> y * (image -> data -> zoom);
	b -> dx = b -> x * (image -> data -> zoom);
	// isometric(a, b);
	dy = ABS((b -> dy) - (a -> dy));
	dx = ABS((b -> dx) - (a -> dx));
	max = MAX(dy, dx);
	dy /= max;
	dx /= max;
	while ((int)((b -> dx) - (a -> dx)) || (int)((b -> dy) - (a -> dy)))
	{
		img_pix_put(image, a -> dx, a -> dy, COLOR(a -> z));
		a -> dx += dx;
		a -> dy += dy;
	}

}

void    set_image(t_data *data)
{
    ssize_t	i;
	ssize_t	j;
	int		z;
	int		z1;
	
	j = -1;
    i = -1;
	z1 = 0;
    while (data -> points[++i])
    {
		z = 20;
        while (++j < data -> tablen)
		{
			if (j < data -> tablen - 1)
				draw_line(data -> image, &data -> points[i][j], 
					&data -> points[i][j+1]);
			if (data -> points[i + 1])
				draw_line(data -> image, &data -> points[i][j], 
					&data -> points[i + 1][j]);
			z +=20;
		}
		z1 += 20;
		j = -1;
    }
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image -> mlx_img, 0, (data -> height / 2));
    
}