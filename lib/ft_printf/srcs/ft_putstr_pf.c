/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:33:28 by eukwon            #+#    #+#             */
/*   Updated: 2022/07/14 11:24:51 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr_pf(const char *str)
{
	int	ret;

	ret = 0;
	if (str == NULL)
	{
		ft_putstr_pf("(null)");
		return (6);
	}
	while (*str)
	{
		ft_putchar_pf(*str++);
		ret++;
	}
	return (ret);
}
