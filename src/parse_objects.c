/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjerinic <fjerinic@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:07:25 by fjerinic          #+#    #+#             */
/*   Updated: 2023/06/11 02:16:08 by fjerinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	parse_plane(char **str, t_scene *scene)
{
	t_figures	*temp;

	add_end_f(&scene->figures);
	temp = scene->figures;
	while (temp->next)
		temp = temp->next;
	temp->flag = PL;
	next(str, scene);
	temp->figures.pl.center = read_vector(str, scene, 0);
	next(str, scene);
	temp->figures.pl.orientation = read_vector(str, scene, 2);
	next(str, scene);
	temp->color = read_vector(str, scene, 1);
	next(str, scene);
}

void	parse_sphere(char **str, t_scene *scene)
{
	t_figures	*temp;

	add_end_f(&scene->figures);
	temp = scene->figures;
	while (temp->next)
		temp = temp->next;
	temp->flag = SP;
	next(str, scene);
	temp->figures.sp.center = read_vector(str, scene, 0);
	next(str, scene);
	temp->figures.sp.radius = dub(str, scene, 2) / 2;
	next(str, scene);
	temp->color = read_vector(str, scene, 1);
	next(str, scene);
}

void	parse_cylinder(char **str, t_scene *scene)
{
	t_figures	*temp;

	add_end_f(&scene->figures);
	temp = scene->figures;
	while (temp->next)
		temp = temp->next;
	temp->flag = CY;
	next(str, scene);
	temp->figures.cy.center = read_vector(str, scene, 0);
	next(str, scene);
	temp->figures.cy.normal_vec3 = normalize_vec3(read_vector(str, scene, 0));
	next(str, scene);
	temp->figures.cy.radius = dub(str, scene, 0) / 2;
	next(str, scene);
	temp->figures.cy.height = dub(str, scene, 0);
	next(str, scene);
	temp->color = read_vector(str, scene, 1);
	next(str, scene);
}

