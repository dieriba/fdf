#include "fdf.h"

void	set_num_color(t_cord *point, char ***tabs, char *str)
{
	char	**tab;

	tab = ft_split(str, ',');
	if (!tab)
		free_tabs(point -> data, &tabs, NULL, 1);
	point -> z = ft_atoi(tab[0]);
	point -> color = ft_atoi(tab[1]);
	ft_free_tab(tab);
}

void	set_cord(t_data *data, char ***tabs)
{
	t_cord	**points;
	size_t	i;
	size_t	j;
	
	j = -1;
	i = -1;
	points = ft_calloc(sizeof(t_cord *), data -> tabrow + 1);
	if (!points)
		free_tabs(data, &tabs, NULL, 0);
	while (tabs[++i])
	{
		j = -1;
		points[i] = ft_calloc(sizeof(t_cord), data -> tablen + 1);
		while (tabs[i][++j])
		{
			points[i][j].x  = j;
			points[i][j].y = i;
			if (!ft_strchr(tabs[i][j], ','))
				points[i][j].z = ft_atoi(tabs[i][j]);
			else
				set_num_color(&points[i][j], tabs, tabs[i][j]);
		}
	}
	data -> points = points;
	free_tabs(data, &tabs, NULL, 0);
}

char	***get_tabs(t_data *data)
{
	char	**tab;
	char	***tabs;
	int		tablen;
	int		i;

	i = -1;
	tab = ft_split(data -> maps, '\n');
	if (!tab)
		print_err_and_exit(data, "error with memory allocation", 0);
	tablen = ft_tab_len(tab);
	data -> tabrow = tablen;
	tabs = ft_calloc(sizeof(char**), tablen + 1);
	if (!tabs)
		free_tabs(data, &tabs, tab, 1);
	while (++i < tablen)
	{
		tabs[i] = ft_split(tab[i], ' ');
		if (!tabs[i])
			free_tabs(data, &tabs, tab, 1);
	}
	ft_free_tab(tab);
	free(data -> maps);
	data -> maps = NULL;
	return (tabs);
}

void	read_maps(t_data *data, char **maps)
{
	int		fd;
	char	*line;
	char	*tmp;

	line = NULL;
	fd = open((*maps), O_RDONLY);
	if (fd == -1)
		print_err_and_exit(data, "Error", 1);
	while (1)
	{
		tmp = get_next_line(fd, 1);
		if (!tmp)
			break ;
		line = ft_strjoin(line, tmp);
		if (!line)
		{
			free(tmp);
			print_err_and_exit(data, "error with allocation memory", 0);
		}
		free(tmp);
	}
	get_next_line(fd, 0);
	(*maps) = line;
}


void    parse_maps(t_data *data)
{
	char	***tabs;

    read_maps(data, &data -> maps);
	tabs = get_tabs(data);
	data -> tablen = ft_tab_len(*tabs);
	set_cord(data, tabs);
	print_struct(data);
}