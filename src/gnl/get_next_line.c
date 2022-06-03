/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:27:02 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/01 18:46:01 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * FUNCTION:	get_next_line
 * --------------------------
 * PROTOTYPE:	char	*get_next_line(int fd);
 * PARAMETERS:
 * 	fd:	The file descriptor to read from
 * RETURNS: The read line if nothing fails, NULL if there is nothin else to
 * read, or an error occurred.
 * DESCRIPTION: Write a function that returns a line read from a file
 * descriptor.
 * DEV: The function first checks if the input is valid. Then, it allocates
 * enough memory for the given buffer size and reads from the file descriptor.
 * The returned buffer is checked to see if it contains '\n', or if sz == 0.
 * If any of the two cases is true, the index of the occurence is returned 
 * (+1) in the case of '\n', and ft_get_line() is called to get the line and
 * save the remainder to the static buffer. It does so by using ft_substr()
 * defined in get_next_line_utils.c.  In the case neither '\n' nor sz == 0
 * is found, the static buffer is set to the temp buffer using ft_substr(), 
 * and a recursive call to get_next_line is executed, starting over the whole
 * process.
 * BONUS DEV: To obtain the current limit of file descriptors, use:
 * "ulimit -n". 4096 is chosen to have a big overhead in most machines.  
 */

static int	ft_buffer_has_line(char *tmp_buffer, int sz)
{
	unsigned int	i;

	i = 0;
	while (tmp_buffer[i] != '\0')
	{
		if (tmp_buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	if (sz == 0)
		return (i);
	return (-1);
}

static int	ft_allocate_and_read(char **tmp_buffer, char **buffer,
			int *sz, int fd)
{
	unsigned int	buf_len;

	if (*buffer)
	{
		buf_len = ft_strlen(*buffer);
		*tmp_buffer = malloc((buf_len + BUFFER_SIZE + 1) * sizeof(char));
		if (!*tmp_buffer)
		{
			free(*buffer);
			return (0);
		}
		ft_strset(tmp_buffer, 0, buf_len + BUFFER_SIZE + 1);
		ft_strcpy(tmp_buffer, buffer, buf_len);
		*sz = read(fd, &(*tmp_buffer)[buf_len], BUFFER_SIZE);
		free(*buffer);
		*buffer = NULL;
		return (1);
	}
	*tmp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!*tmp_buffer)
		return (0);
	ft_strset(tmp_buffer, 0, BUFFER_SIZE + 1);
	*sz = read(fd, *tmp_buffer, BUFFER_SIZE);
	return (1);
}

static int	ft_get_line(char **line, char **tmp_buffer, char **buffer,
			int start_nl)
{
	*line = ft_substr(tmp_buffer, 0, start_nl);
	if (!(*line))
	{
		free(*tmp_buffer);
		return (0);
	}
	*buffer = ft_substr(tmp_buffer, start_nl,
			ft_strlen(*tmp_buffer) - start_nl);
	if (!(*buffer))
	{
		free(*tmp_buffer);
		free(*line);
		return (0);
	}
	if (!(*buffer)[0])
	{
		free(*buffer);
		*buffer = NULL;
	}
	free(*tmp_buffer);
	return (1);
}

static int	ft_validate_and_allocate(char **tmp_buffer, char **buffer,
			int *sz, int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!ft_allocate_and_read(tmp_buffer, buffer, sz, fd))
		return (0);
	if (*sz < 0 || (*sz == 0 && *tmp_buffer[0] == '\0'))
	{
		free(*tmp_buffer);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*tmp_buffer;
	char		*line;
	int			sz;
	int			start_nl;

	if (!ft_validate_and_allocate(&tmp_buffer, &buffer[fd], &sz, fd))
		return (0);
	start_nl = ft_buffer_has_line(tmp_buffer, sz);
	if (start_nl != -1)
	{
		if (!ft_get_line(&line, &tmp_buffer, &buffer[fd], start_nl))
			return (0);
		return (line);
	}
	buffer[fd] = ft_substr(&tmp_buffer, 0, ft_strlen(tmp_buffer));
	if (!buffer[fd])
		return (0);
	free(tmp_buffer);
	return (get_next_line(fd));
}
