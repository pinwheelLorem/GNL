/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <fgabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:37:11 by fgabri            #+#    #+#             */
/*   Updated: 2022/12/12 21:10:26 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 7
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	ft_strlen(char *str);
int	ft_ins(char *str, char c);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif