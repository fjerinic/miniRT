/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjerinic <fjerinic@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:33:18 by gskrasti          #+#    #+#             */
/*   Updated: 2023/06/27 05:16:24 by fjerinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int argc, char *argv[])
{
	t_window	mlx;
	t_scene		*scene;

	// scene = malloc(sizeof(t_scene));
	// mlx.scene = scene;
	// scene->zoom_factor = ZOOM;
	// scene->amb_light = malloc(sizeof(t_amb_light));
	// scene->amb_light->light_ratio = 0.2;
	// scene->amb_light->color.x = 255;
	// scene->amb_light->color.y = 255;
	// scene->amb_light->color.z = 255;
	// scene->camera = malloc(sizeof(t_camera));
	// scene->camera->viewpoint.x = 0;
	// scene->camera->viewpoint.y = -5;
	// scene->camera->viewpoint.z = 30;
	// scene->camera->normal_vec3.x = 0;
	// scene->camera->normal_vec3.y = 0;
	// scene->camera->normal_vec3.z = 1;
	// scene->camera->fov = 53;
	// scene->light = malloc(sizeof(t_light));
	// scene->light->light_point.x = 0;
	// scene->light->light_point.y = 40;
	// scene->light->light_point.z = -10;
	// scene->light->light_brightness = 0.6;
	// scene->num_spheres = 3;
	// scene->sphere = malloc(sizeof(t_sphere) * scene->num_spheres);
	// scene->sphere[0].center.x = 0;
	// scene->sphere[0].center.y = 0;
	// scene->sphere[0].center.z = 10;
	// scene->sphere[0].radius = 3;
	// scene->sphere[0].color.x = 10;
	// scene->sphere[0].color.y = 0;
	// scene->sphere[0].color.z = 255;
	// scene->sphere[1].center.x = 10;
	// scene->sphere[1].center.y = 0;
	// scene->sphere[1].center.z = 22.6;
	// scene->sphere[1].radius = 3;
	// scene->sphere[1].color.x = 10;
	// scene->sphere[1].color.y = 255;
	// scene->sphere[1].color.z = 0;
	// scene->sphere[2].center.x = 1;
	// scene->sphere[2].center.y = 0;
	// scene->sphere[2].center.z = 11.6;
	// scene->sphere[2].radius = 3;
	// scene->sphere[2].color.x = 255;
	// scene->sphere[2].color.y = 10;
	// scene->sphere[2].color.z = 0;
	// // scene->plane = malloc(sizeof(t_plane));
	// // scene->plane->point.x = 0;
	// // scene->plane->point.y = 0;
	// // scene->plane->point.z = -10;
	// // scene->plane->normal_vec3.x = 0;
	// // scene->plane->normal_vec3.y = 1;
	// // scene->plane->normal_vec3.z = 0;
	// // scene->plane->color.x = 0;
	// // scene->plane->color.y = 0;
	// // scene->plane->color.z = 255;
	// scene->num_cylinders = 3;
	// scene->cylinder = malloc(sizeof(t_cylinder) * scene->num_cylinders);
	// scene->cylinder[0].center.x = 0;
	// scene->cylinder[0].center.y = 4;
	// scene->cylinder[0].center.z = 10;
	// scene->cylinder[0].normal_vec3.x = 0;
	// scene->cylinder[0].normal_vec3.y = 1;
	// scene->cylinder[0].normal_vec3.z = 0;
	// scene->cylinder[0].radius = 2;
	// scene->cylinder[0].height = 8;
	// scene->cylinder[0].color.x = 255;
	// scene->cylinder[0].color.y = 10;
	// scene->cylinder[0].color.z = 255;
	// // scene->cylinder[0].top_normal.x = 0;
	// // scene->cylinder[0].top_normal.y = 1;
	// // scene->cylinder[0].top_normal.z = 0;
	// // scene->cylinder[0].bottom_normal.x = 0;
	// // scene->cylinder[0].bottom_normal.y = -1;
	// // scene->cylinder[0].bottom_normal.z = 0;
	// scene->cylinder[1].center.x = 10;
	// scene->cylinder[1].center.y = 0;
	// scene->cylinder[1].center.z = 10;
	// scene->cylinder[1].normal_vec3.x = 0;
	// scene->cylinder[1].normal_vec3.y = 1;
	// scene->cylinder[1].normal_vec3.z = 0;
	// scene->cylinder[1].radius = 1.5;
	// scene->cylinder[1].height = 5;
	// scene->cylinder[1].color.x = 255;
	// scene->cylinder[1].color.y = 255;
	// scene->cylinder[1].color.z = 10;
	// // scene->cylinder[1].top_normal.x = 0;
	// // scene->cylinder[1].top_normal.y = 1;
	// // scene->cylinder[1].top_normal.z = 0;
	// // scene->cylinder[1].bottom_normal.x = 0;
	// // scene->cylinder[1].bottom_normal.y = -1;
	// // scene->cylinder[1].bottom_normal.z = 0;
	// scene->cylinder[2].center.x = -10;
	// scene->cylinder[2].center.y = 0;
	// scene->cylinder[2].center.z = 10;
	// scene->cylinder[2].normal_vec3.x = 0;
	// scene->cylinder[2].normal_vec3.y = 1;
	// scene->cylinder[2].normal_vec3.z = 0;
	// scene->cylinder[2].radius = 1.5;
	// scene->cylinder[2].height = 6;
	// scene->cylinder[2].color.x = 10;
	// scene->cylinder[2].color.y = 255;
	// scene->cylinder[2].color.z = 10;
	// // scene->cylinder[2].top_normal.x = 0;
	// // scene->cylinder[2].top_normal.y = 1;
	// // scene->cylinder[2].top_normal.z = 0;
	// // scene->cylinder[2].bottom_normal.x = 0;
	// // scene->cylinder[2].bottom_normal.y = -1;
	// // scene->cylinder[2].bottom_normal.z = 0;
	
	if (argc < 2)
		fatal_error("no file");
	if (!ft_strnstr(argv[1], ".rt", ft_strlen(argv[1])))
		fatal_error("incorect file");
	scene = parse_scene(argv[1]);
	
	// mlx.width = 1920;
	// mlx.height = 1280;
	scene->camera->height = mlx.height;
	scene->camera->width = mlx.width;
	//mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "miniRT");
	ft_new_img(&mlx, scene);
	mlx_key_hook(mlx.mlx_win, ft_key_hook, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, ft_close, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
