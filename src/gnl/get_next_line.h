/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:48:29 by surkim            #+#    #+#             */
/*   Updated: 2023/12/29 19:28:21 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_list_gnl{
	int					fd;
	char				*str;
	struct s_list_gnl	*next;
}t_list_gnl;

char		*get_next_line(int fd);
char		*ft_strdup_gnl(const char *s1);
char		*ft_strjoin_gnl(char *s1, char *s2, size_t s1_len, size_t s2_len);
char		*ft_strchr_gnl(char *s, int c);
t_list_gnl	*find_fd_list(int fd, t_list_gnl **head);
char		*ft_free_gnl(t_list_gnl **list, char **s1, char *s2, int fd);

#endif