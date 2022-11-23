/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:26:02 by eukwon            #+#    #+#             */
/*   Updated: 2022/11/15 19:38:04 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define FD_MAX 256
# define BUFFER_SIZE 8096

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// size_t	ft_strlen(const char *s);
// char	*ft_strchr(const char *s, int c);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strdup(const char *s1);
void	split_nl(char **fd_list_fd, char **temp);
int		read_buff(int fd, char **fd_list, char **temp);
char	*read_line(int fd, char **fd_list);
char	*get_next_line(int fd);

#endif
