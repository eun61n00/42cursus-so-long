/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:56:09 by eukwon            #+#    #+#             */
/*   Updated: 2022/11/22 12:09:57 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/get_next_line.h"
#include "../lib/minilibx/mlx.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

// int main(int argc, char* argv[])
// {
// 	int fd;

// 	check_params(argc, argv);

// 	if ((fd = open(argv[1], O_RDONLY)) == -1)
// 	{
// 		ft_printf("Fail to open %s\n", argv[1]);
// 		exit(0);
// 	}
// 	get_next_line(fd);
// 	// ft_printf("%s\n", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }

// void	map_read(char *filename, t_game *game)
// {
// 	int  fd;
// 	char *line;

// 	fd = open(filename, O_RDONLY);
// 	line = get_next_line(fd);
// 	game->hei = 0;
// 	game->wid = ft_strlen(line) - 1;
// 	game->str_line = ft_strdup_without_newline(line);
// 	free(line);
// 	while (line)
// 	{
// 		game->hei++;
// 		line = get_next_line(fd);
// 		if (line)
// 		{
// 			game->str_line = ft_strjoin_without_newline(game->str_line, line);
// 		}
// 	}
// 	close(fd);
// 	printf("%s\n", game->str_line);
// }

int main()
{
	void *mlx;
	void *win;
	void *img;
	void *img2;
	void *img3;
	void *img4;
	void *img5;
	void *img6;
	void *img7;
	int img_width;
	int img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "./assets/mario.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "./assets/wall.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "./assets/grass.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "./assets/exit.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx, "./assets/coin.xpm", &img_width, &img_height);

	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 64, 0);
	mlx_put_image_to_window(mlx, win, img3, 128, 0);
	mlx_put_image_to_window(mlx, win, img4, 192, 64);
	mlx_put_image_to_window(mlx, win, img5, 0, 64);

	mlx_loop(mlx);
	return (0);
}