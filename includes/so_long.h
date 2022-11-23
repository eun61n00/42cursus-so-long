/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:07:01 by eukwon            #+#    #+#             */
/*   Updated: 2022/11/23 18:39:16 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../lib/minilibx/mlx.h"
#include "../lib/ft_printf/includes/ft_printf.h"
#include "../includes/get_next_line.h"
#include <stdlib.h>

# define KEY_PRESS	2
# define KEY_RELEASE 3
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_param{
	int		x;
	int		y;
}				t_param;

typedef struct s_game {
	void	*mlx;
	void	*win;
	char	*file;
	char	*map;
	int		width;
	int		height;
	int		c_cnt;
	int		e_cnt;
	int		p_cnt;
	int		move_cnt;
	void	*img_grass;
	void	*img_character;
	void	*img_wall;
	void	*img_exit;
	void	*img_coin;
}	t_game;

void 	check_params(int argc, char *argv[]);
void	print_error(char *error_msg);

#endif