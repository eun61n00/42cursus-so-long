/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:32:25 by eukwon            #+#    #+#             */
/*   Updated: 2022/07/14 11:24:51 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	check_type2(int *ret, char c, va_list *ap)
{
	char	*chr_ptr;

	if (c == 'i')
	{
		chr_ptr = ft_itoa(va_arg(*ap, int));
		*ret += ft_putstr_pf(chr_ptr);
		free(chr_ptr);
	}
	else if (c == 'u')
		*ret += ft_putnbr_base_unsigned(va_arg(*ap, int), "0123456789");
	else if (c == 'X')
		*ret += ft_putnbr_base_unsigned(va_arg(*ap, int), "0123456789ABCDEF");
	else if (c == 'x')
		*ret += ft_putnbr_base_unsigned(va_arg(*ap, int), "0123456789abcdef");
	else if (c == '%')
		*ret += ft_putchar_pf('%');
	else
		return (-1);
	return (0);
}

static int	check_type(int *ret, char c, va_list *ap)
{
	if (c == 'c')
		*ret += ft_putchar_pf(va_arg(*ap, int));
	else if (c == 's')
		*ret += ft_putstr_pf(va_arg(*ap, char *));
	else if (c == 'p')
	{
		*ret += ft_putstr_pf("0x");
		*ret += ft_putaddr((va_arg(*ap, void *)), "0123456789abcdef");
	}
	else if (c == 'd')
		*ret += ft_putnbr_base(va_arg(*ap, int), "0123456789");
	else
		return (check_type2(ret, c, ap));
	return (0);
}

static void	parse(int *ret, const char *string, va_list *ap)
{
	while (*string)
	{
		if (*string != '%')
			*ret += ft_putchar_pf(*string);
		else
		{
			string++;
			if (check_type(ret, *string, ap) == -1)
				return ;
		}
		string++;
	}
}

int	ft_printf(const char *string, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	va_start(ap, string);
	parse(&ret, string, &ap);
	va_end(ap);
	return (ret);
}
