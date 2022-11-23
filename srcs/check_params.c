/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:06:24 by eukwon            #+#    #+#             */
/*   Updated: 2022/11/15 16:05:25 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void check_params(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("USAGE: ./so_long [A map in format *.ber]\n");
		exit(0);
	}

}