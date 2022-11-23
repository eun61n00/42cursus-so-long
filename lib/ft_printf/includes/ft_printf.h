/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:34:06 by eukwon            #+#    #+#             */
/*   Updated: 2022/11/23 17:33:27 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *string, ...);
size_t	ft_strlen(const char *str);
int		ft_putchar_pf(const char c);
int		ft_putstr_pf(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strdup_without_newline(const char *s1);
char	*ft_strjoin_without_newline(char const *s1, char const *s2);
int		ft_putnbr_base(const int nbr, const char *base);
int		ft_putnbr_base_unsigned(const int nbr, const char *base);
int		ft_putaddr(const void *ptr_addr, const char *base);
char	*ft_itoa(const int n);

#endif