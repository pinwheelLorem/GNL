/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <fgabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 03:16:09 by fgabri            #+#    #+#             */
/*   Updated: 2022/12/12 21:11:34 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_ins(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_bzero(void *str, size_t n)
{
	while (n--)
		((char *) str)[n] = '\0';
}

void	*ft_calloc(size_t n, size_t size)
{
	size_t	p;
	void	*s;

	p = n * size;
	if (!n || !p)
		return (ft_calloc(1, 1));
	if ((p / n) != size)
		return (NULL);
	s = (void *)malloc(p);
	if (!s)
		return (NULL);
	ft_bzero(s, p);
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	i = -1;
	j = -1;
	str = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}