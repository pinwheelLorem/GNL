/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <fgabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:05:03 by fgabri            #+#    #+#             */
/*   Updated: 2022/12/13 21:45:35 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* the algo of get next line is:
 1_ Initializing a static var (buffer) to  preserve their u in data segment
 after calling the function in main().to have the files'lines
 2_ get the buffer from the file (considering the buffer_size ofc we 
 need to allocate buffeer_size) with the ft_cpy_buff
 3-get the first line from the buffer, means until '\n'.
 4-update the buffer's value to use it in the next functiton's call.
 5_return the line.
   */

#include "get_next_line.h"

static char	*ft_join(char *buf, char *cpy)
{
	char	*str;

	str = ft_strjoin(buf, cpy);
	free(buf);
	return (str);
}

static	char	*ft_cpy_buff(int fd, char *buf)
{
	char	*cpy;
	int		nbytes;

	nbytes = 1;
	if (buf == 0)
		buf = ft_calloc(1, 1);
	cpy = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (nbytes > 0)
	{
		nbytes = read(fd, cpy, BUFFER_SIZE);
		if (nbytes < 0)
		{
			free(cpy);
			return (NULL);
		}
		cpy[nbytes] = '\0';
		buf = ft_join(buf, cpy);
		if (ft_ins(buf, '\n'))
			break ;
	}
	free(cpy);
	return (buf);
}

static char	*ft_get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (buffer[i] == 0)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n' && buffer[i])
		line[i] = '\n';
	return (line);
}

static char	*ft_cpynext_buff(char *buffer)
{
	int		i;
	int		j;
	char	*nline;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	nline = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));

	while (buffer[++i] != '\0')
		nline[j++] = buffer[i];
	free(buffer);
	return (nline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_cpy_buff(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_cpynext_buff(buffer);
	return (line);
}

/*
int	main()
{
	const int	fd = open(av[1], O_RDONLY);
	int			i;
	char		*str;
	if (ac == 3)
	{
		i = atoi(av[2]);
		while (i)
		{
			str = get_next_line(fd);
			if (!str)
			{
				puts("(null)");
				close (fd);
				return (0);
			}
			puts(str);
			free(str);
			i--;
		}
	}
	close(fd);
	return (0);
}

int main(void)
{

	int	fd1;
	int	fd2;
	char *str;
	int c;
	fd1 = open("text1.txt",O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	c = 0;
	while(get_next_line(fd1) && c < 3)
	{
		str = get_next_line(fd1);
		puts(str);
		free(str);
		c++;
	}
	while(get_next_line(fd2) && c < 7)
	{
		str = get_next_line(fd2);
		puts(str);
		free(str);
		c++;

	}
	while(get_next_line(fd1) && c <  11)
	{
		str = get_next_line(fd1);
		puts(str);
		free(str);
		c++;
	}
}*/
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("text.txt", O_RDONLY);
	fd2 = open("text1.txt", O_RDONLY);
	fd3 = open("text2.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
