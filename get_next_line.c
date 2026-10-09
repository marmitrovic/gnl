/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 14:39:29 by marko             #+#    #+#             */
/*   Updated: 2026/09/08 18:26:28 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_stash(fd, stash)
{
	char *buffer;
	ssize_t bytes_read; //signed size type can be negative number

	buffer = malloc((BUFFER_SIZE + 1) *sizeof(char));
	if(!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stash,'\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			{
				free(buffer);
				return (NULL);
			}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}
/*
I am reading text from a file descriptor some text,
writing it to the stash. 
BUFFER_SIZE is the number of bytes the tester wants to check.
The buffer is a small container that holds these bytes with a size of BUFFER_SIZE + 1 (for the \0)
Why do we need that buffer if we can write it directly in the stash? 
Because the buffer might contain 2 or 3 '\n', which we will need to extract later using the stash.
We assumebytes_to_read to be 1 at start, but later we assign BUFFER_SIZE to it.
Then, using the same read function, we append data from the fd into the buffer container.
*/

char *extract_line(char *stash)
{
	int	i = 0;
	int	len = 0;
	if(!stash || !stash[0])
		return (NULL);
	while (stash[len] != '\n' && stash[len] != '\0')
		len++;
	char *line = malloc (len + (stash[len] == '\n') + 1);
	if (!line)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] ='\0';
	return line;
}

/*
	The extrac_line function extracts a string from the stash up to the first \n or \0
	After determining the length, we allocate memory using malloc
	The allocation size is calculated as (len + (stash[len] == '\n') + 1);
	In C, boolean expressions evaluate directly to 1 true or 0 false
	This allows us to conditionally add space for the \n character 
	withouth an if statement, while always adding 1 extra byte for the null-terminator \0

*/

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
/*
	while ( ft_strchr(stash, '\n'), read == 0)
	{
	ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';
	stash = ft_strchr(buffer, fd);
	line = ft_strjoin(buffer, stash);
	free(buffer);
	free(stash);
	return(line);
} */