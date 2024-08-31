/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:18:00 by aalfahal          #+#    #+#             */
/*   Updated: 2023/09/01 17:54:40 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	malloc_all_help(t_map *m)
{
	m->tmp_text_names[no] = ft_strdup("NO");
	m->tmp_text_names[so] = ft_strdup("SO");
	m->tmp_text_names[we] = ft_strdup("WE");
	m->tmp_text_names[ea] = ft_strdup("EA");
	m->tmp_text_names[f] = ft_strdup("F");
	m->tmp_text_names[c] = ft_strdup("C");
	m->tmp_map = malloc(sizeof(char *) * 2);
	if (!m->tmp_map)
		return ;
	m->tmp_map[0] = ft_strdup("anything");
	m->tmp_map[1] = NULL;
}

static void	malloc_all(t_map *m)
{
	int	i;

	i = 0;
	m->tmp_text_names = malloc(sizeof(char *) * 7);
	m->f_c_rgb = malloc(sizeof(int) * 7);
	m->counters = malloc(sizeof(int) * 8);
	m->textures = malloc(sizeof(char *) * 6);
	m->map = malloc(sizeof(char *) * 2);
	if (!m->tmp_text_names || !m->f_c_rgb \
	|| !m->counters || !m->textures || !m->map)
		return ;
	m->map[0] = ft_strdup("anything");
	m->map[1] = NULL;
	ft_bzero(m->textures, sizeof(char *) * 6);
	while (i < 5)
		m->textures[i++] = ft_strdup("Test");
	ft_bzero(m->tmp_text_names, sizeof(char *) * 7);
	ft_bzero(m->f_c_rgb, sizeof(int) * 7);
	ft_bzero(m->counters, sizeof(int) * 8);
	malloc_all_help(m);
}

static void	check_errors(t_cub3d *c)
{
	int	i;

	i = 0;
	malloc_all(c->map);
	check_map_at_end(c);
	i = 0;
	while (c->map->file[i])
		check_in_tmp2d(c, c->map->file[i++], &c->map->tmp_text_names);
	check_file_elements(c);
	check_text_error(c);
	if (c->map->error > 0)
		clean_exit(c, 4, 1);
	check_map_element(c->map);
	if (c->map->error > 0)
		clean_exit(c, 4, 1);
	c->map->map_height = ft_strlen_2d(c->map->map);
}

static void	reading_to2d(t_cub3d *c, char *s, int number_of_lines)
{
	int		fd;
	int		i;
	char	*line;

	c->map->file = malloc(sizeof(char *) * (number_of_lines + 1));
	if (!c->map->file)
		return ;
	fd = open(s, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		c->map->file[i++] = line;
		line = get_next_line(fd);
	}
	c->map->file[i] = 0;
	close(fd);
	if (number_of_lines == 0)
		clean_exit(c, 1, 1);
}

void	reading_map(char *s, t_cub3d *c)
{
	int		fd;
	int		number_of_lines;
	char	*line;

	number_of_lines = 0;
	c->map = malloc(sizeof(t_map) * 1);
	if (!c->map)
		return ;
	ft_bzero(c->map, sizeof(t_map) * 1);
	fd = open(s, O_RDONLY);
	if (ft_filecmp(s, ".cub", ft_strlen(s) - 4) == 1)
		closing_and_freeing(c->map, fd, NULL, 1);
	if (fd < 0)
		closing_and_freeing(c->map, fd, NULL, 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		remove_space(line);
		number_of_lines++;
		free(line);
		line = get_next_line(fd);
	}
	closing_and_freeing(NULL, fd, line, 0);
	reading_to2d(c, s, number_of_lines);
	check_errors(c);
}
