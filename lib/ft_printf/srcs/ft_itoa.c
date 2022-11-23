/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:20:54 by eukwon            #+#    #+#             */
/*   Updated: 2022/07/14 11:24:51 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	get_digit(const int n)
{
	unsigned int	unsigned_n;
	size_t			digit;

	digit = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		unsigned_n = -n;
		digit++;
	}
	else
		unsigned_n = n;
	while (unsigned_n)
	{
		digit++;
		unsigned_n /= 10;
	}
	return (digit);
}

char	*ft_itoa(const int n)
{
	char			*ret;
	unsigned int	unsigned_n;
	size_t			digit;

	if (n == 0)
		return (ft_strdup("0"));
	digit = get_digit(n);
	ret = (char *)malloc(sizeof(char) * (digit + 1));
	if (ret == NULL)
		return (NULL);
	ret[digit] = '\0';
	if (n < 0)
	{
		unsigned_n = -n;
		ret[0] = '-';
	}
	else
		unsigned_n = n;
	while (unsigned_n)
	{
		ret[digit - 1] = unsigned_n % 10 + '0';
		unsigned_n /= 10;
		digit--;
	}
	return (ret);
}
