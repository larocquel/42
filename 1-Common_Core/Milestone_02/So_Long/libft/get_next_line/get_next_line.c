/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:43:35 by leoaguia          #+#    #+#             */
/*   Updated: 2025/02/16 12:39:05 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *file);
char	*ft_take_line(char *buffer);
char	*ft_update_buffer(char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_take_line(buffer);
	buffer = ft_update_buffer(buffer);
	return (line);
}

char	*ft_read_file(int fd, char *file)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	if (!file)
		file = ft_calloc(1, sizeof(char));
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (free(file), NULL);
	bytes_read = 1;
	while (!ft_strchr(file, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(file), NULL);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(file, buffer);
		if (!temp)
			return (free(buffer), free(file), NULL);
		free(file);
		file = temp;
	}
	free(buffer);
	return (file);
}

char	*ft_take_line(char *file)
{
	char	*line;
	size_t	i;

	if (!file || !*file)
		return (NULL);
	i = 0;
	while (file[i] != '\n' && file[i] != '\0')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (file[i] != '\n' && file[i] != '\0')
	{
		line[i] = file[i];
		i++;
	}
	if (file[i] == '\n')
		line[i] = '\n';
	line[++i] = '\0';
	return (line);
}

char	*ft_update_buffer(char *file)
{
	char	*new_buf;
	size_t	i;
	size_t	j;

	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (!file[i])
	{
		free(file);
		return (NULL);
	}
	i++;
	new_buf = ft_calloc(ft_strlen(file) - i + 1, sizeof(char));
	if (!new_buf)
		return (NULL);
	j = 0;
	while (file[i])
		new_buf[j++] = file[i++];
	new_buf[j] = '\0';
	free(file);
	return (new_buf);
}
