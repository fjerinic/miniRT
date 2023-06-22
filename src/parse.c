/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjerinic <fjerinic@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:03:48 by fjerinic          #+#    #+#             */
/*   Updated: 2023/06/11 02:13:28 by fjerinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

// parses the string and calls different 
// parsing functions based on the content of the string
// checks for illegal identifiers in the map

int	parse(char *str, t_scene *scene)
{	
	if (*str == 'p' && *(str + 1) == 'l' && str++)
		parse_plane(&str, scene);
	else if (*str == 'l' && str++)
		parse_light(&str, scene);
	else if (*str == 'A' && str++)
		parse_ambient(&str, scene);
	else if (*str == 'c' && *(str + 1) == 'y' && str++)
		parse_cylinder(&str, scene);
	else if (*str == 'c' && str++)
		parse_camera(&str, scene);
	else if (*str == 's' && *(str + 1) == 'p' && str++)
		parse_sphere(&str, scene);
	{
		print_error("no such identifier:");
		return (print_error(str));
	}
	return (1);
}

// initialization of t_scene struct

void	create_scene(t_scene **scene)
{
	(*scene) = (t_scene *)malloc(sizeof(t_scene));
	(*scene)->figures = NULL;
	(*scene)->light = NULL;
	//(*scene)->mlx = NULL;
	(*scene)->background = 0;
	(*scene)->height = 1080;
	(*scene)->width = 1920;
}

// Opens a file, reads its contents line by line, 
// parses each line using the parse function, 
// updates the scene accordingly. 

t_scene	*parse_scene(char *file_name)
{
	int		fd;
	char	*str;
	t_scene	*scene;

	fd = open(file_name, O_RDONLY);
	scene = NULL;
	if (fd == -1)
		fatal_error("no such file");
	create_scene(&scene);
	//init_mlx(scene);
	str = get_next_line(fd);
	while (str)
	{
		ft_putstr_fd(str, 2);
		if (*str != '\n')
			if (parse(str, scene) == -1)
				parse_error(scene, fd);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (scene);
}
