/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_without_newline.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:27:48 by eukwon            #+#    #+#             */
/*   Updated: 2022/11/23 17:33:34 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strjoin_without_newline(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*joinstr;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joinstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (joinstr == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		if (*s1 != '\n')
			joinstr[i] = *s1++;
		i++;
	}
	while (i < s1_len + s2_len)
	{
		if (*s2 != '\n')
			joinstr[i] = *s2++;
		i++;
	}
	joinstr[i] = '\0';
	return (joinstr);
}