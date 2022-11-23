/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:17:36 by eukwon            #+#    #+#             */
/*   Updated: 2022/07/14 11:24:51 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned int	to_unsigned_int(int *ret, const int nbr)
{
	unsigned int	nbr_u;

	if (nbr < 0)
	{
		write(1, "-", 1);
		*(ret) += 1;
		nbr_u = nbr * (-1);
	}
	else
		nbr_u = nbr;
	return (nbr_u);
}

static void	write_nbr_base(int *ret, uintptr_t nbr_u, \
	const char *base, const int base_num)
{
	if (nbr_u / base_num != 0)
	{
		write_nbr_base(ret, nbr_u / base_num, base, base_num);
		write(1, &base[nbr_u % base_num], 1);
		*(ret) += 1;
	}
	else
	{
		write(1, &base[nbr_u], 1);
		*(ret) += 1;
	}
}

int	ft_putnbr_base(const int nbr, const char *base)
{
	int				base_num;
	unsigned int	nbr_u;
	int				ret;

	ret = 0;
	base_num = 0;
	nbr_u = to_unsigned_int(&ret, nbr);
	while (base[base_num])
		base_num++;
	write_nbr_base(&ret, nbr_u, base, base_num);
	return (ret);
}

int	ft_putnbr_base_unsigned(const int nbr, const char *base)
{
	int	base_num;
	int	ret;

	ret = 0;
	base_num = 0;
	while (base[base_num])
		base_num++;
	write_nbr_base(&ret, (unsigned int)nbr, base, base_num);
	return (ret);
}

int	ft_putaddr(const void *ptr_addr, const char *base)
{
	int	base_num;
	int	ret;

	ret = 0;
	base_num = 0;
	while (base[base_num])
		base_num++;
	write_nbr_base(&ret, (uintptr_t)ptr_addr, base, base_num);
	return (ret);
}
