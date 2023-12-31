/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjerinic <fjerinic@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:07:34 by fjerinic          #+#    #+#             */
/*   Updated: 2023/06/27 05:01:08 by fjerinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	parse_ambient(char **str, t_scene *scene)
{
	scene->amb_light = (t_amb_light *)malloc(sizeof(t_amb_light));
	if (!scene->amb_light)
		fatal_error("Ambient not allocated");
	next(str, scene);
	scene->amb_light->light_ratio = dub(str, scene, 1);
	next(str, scene);
	scene->amb_light->color = read_vector(str, scene, 1);
}

void	parse_camera(char **str, t_scene *scene)
{
	scene->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!scene->camera)
		fatal_error("Camera not allocated");
	next(str, scene);
	scene->camera->viewpoint = read_vector(str, scene, 0);
	next(str, scene);
	scene->camera->normal_vec3 = normalize_vec3(read_vector(str, scene, 0));
	next(str, scene);
	scene->camera->fov = dub(str, scene, 2);
	scene->camera->distance = tan((scene->camera->fov * M_PI / 180) / 2);
}

void	parse_light(char **str, t_scene *scene)
{
	scene->light = (t_light *)malloc(sizeof(t_light));
	if (!scene->light)
		fatal_error("Light not allocated");
	next(str, scene);
	scene->light->light_point = read_vector(str, scene, 0);
	next(str, scene);
	scene->light->light_brightness = dub(str, scene, 1);
	next(str, scene);
}