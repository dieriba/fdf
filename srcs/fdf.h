#ifndef FDF_H
#define FDF_H

typedef struct t_cord;
typedef struct t_data
{
    int width;
    int height;
    t_cord  **point;
}   t_data;

typedef struct t_cord
{
    int x;
    int y;
    int z;
    int color;
}   t_cord;

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>

#endif