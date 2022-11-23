/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_without_newline.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:21:50 by eukwon            #+#    #+#             */
/*   Updated: 2022/11/23 17:22:54 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strdup_without_newline(const char *s1)
{
	size_t	str_len;
	size_t	i;
	char	*dupstr;

	str_len = ft_strlen(s1);
	dupstr = (char *)malloc(sizeof(char) * (str_len + 1));
	if (dupstr == NULL)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		if (s1[i] != '\n')
			dupstr[i] = s1[i];
		i++;
	}
	dupstr[i] = '\0';
	return (dupstr);
}