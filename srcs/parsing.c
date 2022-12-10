#include "fdf.h"







void	free_tabs(t_data *data, char ****tabs, char **tab)
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
	print_err_and_exit(NULL, "Error with memory allocation", 0);
}

void	set_cords(t_data *data)
{
	char	**tab;
	char	***tabs;
	int		tablen;
	size_t	i;

	i = -1;
	tab = ft_split(data -> maps, '\n');
	if (!tab)
		print_err_and_exit(data, "error with memory allocation", 0);
	tablen = ft_tab_len(tab);
	tabs = ft_calloc(sizeof(char**), tablen + 1);
	if (!tabs)
		free_tabs(data, &tabs, tab);
	while (++i < tablen)
	{
		tabs[i] = ft_split(tab[i], ' ');
		if (tabs[i])
			free_tabs(data, &tabs, tab);
	}
	ft_free_tab(tab);
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
    read_maps(data, &data -> maps);
	set_cords(data);
}