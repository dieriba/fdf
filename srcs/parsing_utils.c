#include "fdf.h"

void	print_struct(t_data *data)
{
	int	i;
	int	j;
	t_cord	**points;

	points = data -> points;
	j = -1;
	i = -1;
	while (points[++i])
	{
		while (++j < data -> tablen)
			printf("%3d", points[i][j].z);
		printf("\n");
		j = -1;
	}
}

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