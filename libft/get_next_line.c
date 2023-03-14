/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:50:32 by mvomiero          #+#    #+#             */
/*   Updated: 2023/02/14 18:46:55 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*extract_stash(int fd, char *buf, char *stash)
{
	int		read_value;
	char	*char_temp;

	read_value = 1;
	while (read_value != 0)
	{
		read_value = read(fd, buf, BUFFER_SIZE);
		if (read_value == -1)
			return (0);
		else if (read_value == 0)
			break ;
		buf[read_value] = '\0';
		if (!stash)
			stash = ft_strdup("");
		char_temp = stash;
		stash = ft_strjoin(char_temp, buf);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (stash);
}

static char	*extract_line(char *line)
{
	size_t	pos;
	char	*stash;

	pos = 0;
	while (line[pos] != '\0' && line[pos] != '\n')
		pos++;
	if (line[pos] == '\0' || line [1] == '\0' || line[pos + 1] == '\0')
		return (0);
	stash = ft_substr(line, pos + 1, ft_strlen(line) - pos);
	line[pos + 1] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = extract_stash(fd, buf, stash);
	free(buf);
	buf = NULL;
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = extract_line(line);
	return (line);
}

/* 

// The main to test it. You will habe to make a test.txt file as well and includ
// the headers here below

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char	*line;
	int		i;
	int		fd;

	fd = open("test.txt", O_RDONLY);

	i = 1;
	while (i < 4)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
} */

/* 

// SO HERE THE EXPLANATION STEP BY STEP

static char	*extract_stash(int fd, char *buf, char *stash)
{
	int		read_value;
	// It is an int becuse it is the return value of the read functioon
	char	*char_temp;
	// temp string to temporary store the retrived data and build the raw line

	read_value = 1;
	while (read_value != '\0')
	// while the result value from read is not 0, which means nothing is read
	{
		read_value = read(fd, buf, BUFFER_SIZE);
		if (read_value == -1)
			return (0);
			// This is in case of an error
		else if (read_value == 0)
			break ;
			// because there is nothing more to read
		buf[read_value] = '\0';
		// jou terminate the string
		if (!stash)
			stash = ft_strdup("");
		// if stash is not intialised, you do it dynamically allocated of course
		char_temp = stash;
		stash = ft_strjoin(char_temp, buf);
		free(char_temp);
		char_temp = NULL;
		// you do a swap to and join the stash with the temporary retrived, then
		// you free it
		if (ft_strchr(buf, '\n'))
			break ;
			// if you find the new line of course you stop the retriving
	}
	return (stash);
	// So at this point you have a raw line that you export to be refined and 
	// divided in the line and the remainings (stash)
}

static char	*extract_line(char *line)
{
	size_t	pos;
	char	*stash;

	pos = 0;
	while (line[pos] != '\0' && line[pos] != '\n')
		pos++;
		// while is not \0 or \n of course i go on
	if (line[pos] == '\0' || line [1] == '\0' || line[pos + 1] == '\0')
		return (0);
		// that is for: 1 - the string is terminated, 2 - it means line[0] == \n
		// 3 - it means there is nothing more after to read
	stash = ft_substr(line, pos + 1, ft_strlen(line) - pos);
		// so you make the substring
	line[pos + 1] = '\0';
	return (stash);
		// After the string is terminated and you return it!
}

char	*get_next_line(int fd)
{
	static char	*stash;
	// So this is to store what remains after using the read function, for 
	// the next line
	// static variables preserve their variables even outside their scopes, so 
	// when you call another time the function they won't be reinitialised.
	// they stay while the program is running
	// Are automatically initialized = 0 if you do not initialise them
	char		*buf;
	// buf is the basic string with the size BUFFER_SIZE
	char		*line;
	// line is what we want, the line that we export and so the retourn of the 
	// function

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	// fd can't be less than 0, if not there is a problem with the fd.
	// BUFFER_SIZE can't be <= 0, if not it means it stores nothing.
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	// just declaring buf and having the malloc pointer protection
	line = extract_stash(fd, buf, stash);
	// jou call the function that extracts the raw line.
	free(buf);
	buf = NULL;
	// you don't need buf anymore so you have to free the content and the ptr
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	// if there is nothing in line, you have to free the stash as well!!
	stash = extract_line(line);
	// at the end you refine the line (that you send as parameter) and you store
	// what is left in stash
	return (line);
	// You just return the line
} */
