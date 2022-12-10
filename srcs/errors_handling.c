#include "fdf.h"








int	ft_error(char *str, int code)
{
	ft_putendl_fd(str, 1);
	exit (code);
}

void	free_all(t_data *data)
{	
	size_t	i;
	
	i = -1;
	if (data -> points)
	{
		while (data -> points[++i])
			free(data -> points[i]);
		free(data -> points);
	}
	if (data -> maps)
		free(data -> maps);
}

void    print_err_and_exit(t_data *data, char *str, int syserror)
{
	if (syserror)
		perror(str);
	else
		ft_putstr_fd(str, 2);
	if (data)
		free_all(data);
	exit(EXIT_FAILURE);
}