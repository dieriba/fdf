/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:57:29 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/15 14:57:47 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (data -> mlx_ptr && data -> image -> mlx_img)
		mlx_destroy_image(data -> mlx_ptr, data -> image -> mlx_img);
	if (data -> mlx_ptr)
	{
		mlx_destroy_window(data -> mlx_ptr, data -> win_ptr);
		mlx_destroy_display(data -> mlx_ptr);
		free(data -> mlx_ptr);
	}
}

void	print_err_and_exit(t_data *data, char *str, int syserror)
{
	if (syserror)
		perror(str);
	else
		ft_putstr_fd(str, 2);
	if (data)
		free_all(data);
	exit(EXIT_FAILURE);
}
