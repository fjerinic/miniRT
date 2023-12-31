/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjerinic <fjerinic@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:07:25 by fjerinic          #+#    #+#             */
/*   Updated: 2023/06/27 05:11:44 by fjerinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	parse_plane(char **str, t_scene *scene)
{
	scene->plane = (t_plane *)malloc(sizeof(t_plane));
	if (!scene->plane)
		fatal_error("Plane not allocated");
	next(str, scene);
	scene->plane->point = read_vector(str, scene, 0);
	next(str, scene);
	scene->plane->normal_vec3 = normalize_vec3(read_vector(str, scene, 2));
	next(str, scene);
	scene->plane->color = read_vector(str, scene, 1);
	next(str, scene);
}

void	parse_sphere(char **str, t_scene *scene)
{
	scene->sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!scene->sphere)
		fatal_error("Sphere not allocated");
	next(str, scene);
	scene->sphere->center = read_vector(str, scene, 0);
	next(str, scene);
	scene->sphere->radius = dub(str, scene, 2) / 2;
	next(str, scene);
	scene->sphere->color = read_vector(str, scene, 1);
	next(str, scene);
}

void	parse_cylinder(char **str, t_scene *scene)
{
	scene->cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!scene->cylinder)
		fatal_error("Cylinder not allocated");
	next(str, scene);
	scene->cylinder->center = read_vector(str, scene, 0);
	next(str, scene);
	scene->cylinder->normal_vec3 = normalize_vec3(read_vector(str, scene, 0));
	next(str, scene);
	scene->cylinder->radius = dub(str, scene, 0) / 2;
	next(str, scene);
	scene->cylinder->height = dub(str, scene, 0);
	next(str, scene);
	scene->cylinder->color = read_vector(str, scene, 1);
	next(str, scene);
}

