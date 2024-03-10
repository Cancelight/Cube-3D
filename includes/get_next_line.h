/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:52:58 by agaygisi          #+#    #+#             */
/*   Updated: 2022/12/10 15:49:08 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	gnl_strlen(char *str);
char	*ft_refactor(char *left);
char	*ft_fill_buffer(int fd, char *str);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*gnl_strjoin(char *str, char *buff);
char	*gnl_strchr(char *str, int c);
char	*ft_get_line(char *str);
char	*ft_last_str(char *str);
#endif
