/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:49:19 by eukwon            #+#    #+#             */
/*   Updated: 2022/11/23 18:50:46 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	split_nl(char **fd_list_fd, char **temp)
{
	char	*nl;
	char	*temp2;

	nl = ft_strchr((*fd_list_fd), '\n');
	if (!nl)
	{
		*temp = ft_strdup(*fd_list_fd);
		free(*fd_list_fd);
		*fd_list_fd = NULL;
		return ;
	}
	*temp = ft_substr((*fd_list_fd), 0, (nl - (*fd_list_fd)) + 1);
	temp2 = ft_strdup(ft_strchr((*fd_list_fd), '\n') + 1);
	free((*fd_list_fd));
	(*fd_list_fd) = temp2;
}

int	read_buff(int fd, char **fd_list, char **temp)
{
	int		ret;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	ret = read(fd, buff, BUFFER_SIZE);
	if (ret <= 0)
	{
		free(buff);
		if (ft_strlen(fd_list[fd]) > 0)
		{
			split_nl(&fd_list[fd], temp);
			return (0);
		}
		else
			return (-1);
	}
	buff[ret] = '\0';
	*temp = ft_strjoin(fd_list[fd], buff);
	free(buff);
	buff = NULL;
	free(fd_list[fd]);
	fd_list[fd] = *temp;
	return (1);
}

char	*read_line(int fd, char **fd_list)
{
	int		ret;
	char	*newl;
	char	*temp;

	newl = NULL;
	temp = NULL;
	while (!newl)
	{
		ret = read_buff(fd, fd_list, &temp);
		if (ret == -1)
			return (NULL);
		else if (ret == 0)
		{
			if (ft_strlen(temp) > 0)
				return (temp);
			free(temp);
			temp = NULL;
			return (NULL);
		}
		else
			newl = ft_strchr(fd_list[fd], '\n');
	}
	split_nl(&fd_list[fd], &temp);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*fd_list[OPEN_MAX + 1];

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE < 0)
		return (NULL);
	ret = read_line(fd, fd_list);
	if (!ret)
	{
		free(fd_list[fd]);
		return (NULL);
	}
	return (ret);
}
