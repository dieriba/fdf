#ifndef FDF_H
#define FDF_H

typedef struct	t_cord t_cord;
typedef struct	t_data t_data;



typedef struct t_cord
{
    int		x;
    int		y;
    int		z;
    int		color;
    t_data	*data;
}	t_cord;

typedef struct	t_data
{
    char	*maps;
	int		tabrow;
    int		tablen;
    int		width;
    int		height;
    t_cord	**points;
}   t_data;


# include <stdio.h>
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

int		ft_error(char *str, int code);
void	print_struct(t_data *data);
void    parse_maps(t_data *data);
void    print_err_and_exit(t_data *data, char *str, int syserror);
void	free_tabs(t_data *data, char ****tabs, char **tab, int err);

#endif