/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjerinic <fjerinic@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:07:34 by fjerinic          #+#    #+#             */
/*   Updated: 2023/06/26 19:33:58 by fjerinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

// t_lights	*new_lst_l(void)
// {
// 	t_lights	*new;

// 	new = (t_lights *)malloc(sizeof(t_lights));
// 	new->next = NULL;
// 	return (new);
// }

// void	add_end_l(t_lights **light)
// {
// 	t_lights	*temp;

// 	if (!(*light))
// 	{
// 		*light = new_lst_l();
// 		return ;
// 	}
// 	temp = *light;
// 	while (temp->next)
// 		temp = temp->next;
// 	temp->next = new_lst_l();
// }

void	parse_ambient(char **str, t_scene *scene)
{
	next(str, scene);
	scene->a_scale = dub(str, scene, 1);
	next(str, scene);
	scene->a_color = read_vector(str, scene, 1);
	scene->aspect_ratio = (double)scene->width / (double)scene->height;
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
	t_lights	*temp;

	add_end_l(&scene->lights);
	temp = scene->lights;
	while (temp->next)
		temp = temp->next;
	next(str, scene);
	temp->light.light_point = read_vector(str, scene, 0);
	next(str, scene);
	temp->light.light_brightness = dub(str, scene, 1);
	next(str, scene);
}