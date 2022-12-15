/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:15:31 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/15 15:00:10 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tabs(t_data *data, char ****tabs, char **tab, int err)
{
	size_t	i;
	char	***tmp;

	tmp = *tabs;
	i = -1;
	if (tmp)
	{
		while (tmp[++i])
			ft_free_tab(tmp[i]);
		free(tmp);
		*tabs = NULL;
	}
	if (tab)
		ft_free_tab(tab);
	if (err)
		print_err_and_exit(data, "Error with memory allocation", 0);
}

int	find_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	color(t_cord *a, t_cord *b)
{
	if (a -> z || b -> z)
		return (0xFF0000);
	return (0xFFFFFF);
}
