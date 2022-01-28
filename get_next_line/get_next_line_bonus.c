/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 01:37:44 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/28 05:46:39 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*topata(char *readed)
{
	char	*newline;
	int		i;
	int		j;

	i = 0;
	while (readed[i] && readed[i] != '\n')
		i++;
	if (!readed[i])
	{
		free(readed);
		return (NULL);
	}
	newline = (char *)malloc(sizeof(char) * (ft_strlen(readed) - i + 1));
	if (!newline)
		return (NULL);
	i += 1;
	j = 0;
	while (readed[i])
		newline[j++] = readed[i++];
	newline[j] = '\0';
	free(readed);
	return (newline);
}

char	*find_line(char *readed)
{
	char	*line;
	int		i;

	i = 0;
	if (!readed[i])
		return (NULL);
	while (readed[i] && readed[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (readed[i] && readed[i] != '\n')
	{
		line[i] = readed[i];
		i++;
	}
	if (readed[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_line(int fd, char *readed)
{
	int		i;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = 1;
	while (!ft_strchr(readed, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			free(readed);
			return (NULL);
		}
		buffer[i] = '\0';
		readed = ft_strjoin(readed, buffer);
	}
	free (buffer);
	return (readed);
}

char	*get_next_line(int fd)
{
	static char	*readed[257];
	char		*line;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!readed[fd])
		readed[fd] = ft_strdup("");
	readed[fd] = read_line(fd, readed[fd]);
	if (!readed[fd])
		return (NULL);
	line = find_line(readed[fd]);
	readed[fd] = topata(readed[fd]);
	return (line);
}
