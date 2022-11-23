/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:56:09 by eukwon            #+#    #+#             */
/*   Updated: 2022/11/23 19:01:25 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/get_next_line.h"
#include "../lib/minilibx/mlx.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void			param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

int				key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		param->y++;
	else if (keycode == KEY_S)
		param->y--;
	else if (keycode == KEY_A)
		param->x--;
	else if (keycode == KEY_D)
		param->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	ft_printf("x: %d, y: %d\n", param->x, param->y);
	return (0);
}

void	init_game(t_game *game, char *file)
{
	int	img_width;
	int	img_height;

	game->file = file;
	game->map = ft_strdup("");
	if (game->map == NULL)
		ft_printf("System error, reboot game");
	game->mlx = mlx_init();
	game->c_cnt = 0;
	game->e_cnt = 0;
	game->p_cnt = 0;
	game->move_cnt = 0;
	game->img_grass = mlx_xpm_file_to_image(game->mlx,
			"./asset/grass.xpm", &img_width, &img_height);
	game->img_character = mlx_xpm_file_to_image(game->mlx,
			"./asset/person.xpm", &img_width, &img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"./asset/wall.xpm", &img_width, &img_height);
	game->img_coin = mlx_xpm_file_to_image(game->mlx,
			"./asset/coin.xpm", &img_width, &img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"./asset/exit.xpm", &img_width, &img_height);
}

void	map_read(char *filename, t_game *game)
{
	int	fd;
	char *line;

	fd = open(filename, O_RDONLY);
	ft_printf("%d\n", fd);
	line = get_next_line(fd);
	while (line != 0)
	{
		line = get_next_line(fd);
		ft_printf("%s", line);
	}
	// int  fd;
	// char *line;

	// fd = open(filename, O_RDONLY);

	// line = get_next_line(fd);

	// game->map = ft_strjoin_without_newline(game->map, line);
	// while (line)
	// {
	// 	game->height++;
	// 	line = get_next_line(fd);
	// 	if (line)
	// 	{
	// 		game->map = ft_strjoin_without_newline(game->map, line);
	// 	}
	// }
	// close(fd);
	// ft_printf("%s\n", game->map);
}

void	setting_img(t_game game)
{
	int		height;
	int		width;

	height = 0;
	while (height < game.height)
	{
		width = 0;
		while (width < game.width)
		{
			if (game.map[height * game.width + width] == '1')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img_wall, width * 64, height * 64);
			}
			else if (game.map[height * game.width + width] == 'C')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img_coin, width * 64, height * 64);
			}
			else if (game.map[height * game.width + width] == 'P')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img_character, width * 64, height * 64);
			}
			else if (game.map[height * game.width + width] == 'E')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img_exit, width * 64, height * 64);
			}
			else
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img_grass, width * 64, height * 64);
			}
			width++;
		}
		height++;
	}
}

// int			main(int argc, char *argv[])
// {
// 	void		*mlx;
// 	void		*win;
// 	t_param		param;
// 	t_game		game;

// 	param_init(&param);
// 	// mlx = mlx_init();
// 	// win = mlx_new_window(mlx, 500, 500, "mlx_project");
// 	// mlx_hook(win, KEY_RELEASE, 0, &key_press, &param);

// 	if (argc < 2)
// 		print_error("We need argument");
// 	else if (argc > 2)
// 		print_error("Too many arguments");
// 	int i = 0;
// 	// while (argv[1][i] != '\0')
// 	// 	i++;
// 	// if (ft_strncmp(&argv[1][i - 4], ".ber", 4) != 0)
// 	// 	print_error("The file must be *.ber");
// 	// if (open(argv[1], O_RDONLY) < 0)
// 	// 	print_error("Check the file name again");
// 	init_game(&game, argv[1]);

// 	int	fd;
// 	char *line;

// 	fd = open(argv[1], O_RDONLY);
// 	ft_printf("%d\n", fd);
// 	line = get_next_line(fd);
// 	while (line != 0)
// 	{
// 		line = get_next_line(fd);
// 		ft_printf("%s", line);
// 	}
// 	// map_read(argv[1], &game);
// 	// mlx_loop(mlx);
// }

int main(void)
{

	int  fd;
	char *line = ft_strdup("");

	fd = open("./maps/map1.ber", O_RDONLY);
	while (line != NULL)
	{
		line = get_next_line(fd);
		ft_printf("%s", line);
	}
}