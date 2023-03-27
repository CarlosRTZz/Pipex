/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:25:44 by cortiz            #+#    #+#             */
/*   Updated: 2023/03/26 18:52:15 by carlosortiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_left_line(char *src)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!src)
		return (0);
	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	if (src[i] && src[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	j = 0;
	while (j < i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*get_right_line(char *str)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	if (!str)
		return (free_all(&str));
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	j = 0;
	if (!str[i])
		return (free_all(&str));
	while (str[i + j])
		j++;
	dest = malloc(sizeof(char) * (j + 1));
	if (!dest)
		return (free_all(&str));
	j = 0;
	while (++j && str[i + j - 1])
		dest[j - 1] = str[i + j - 1];
	dest[j - 1] = '\0';
	free(str);
	return (dest);
}

char	*get_all_line(int fd, char *str)
{
	char		buffer[BUFFER_SIZE + 1];
	int			read_ret;

	if (!str)
	{
		str = malloc(sizeof(char) + 1);
		if (!str)
			return (free_all(&str));
		str[0] = '\0';
	}
	read_ret = 1;
	while (!has_nl(str) && read_ret > 0)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret == -1)
			return (free_all(&str));
		buffer[read_ret] = '\0';
		str = ft_strjoine(str, buffer);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = get_all_line(fd, str);
	line = get_left_line(str);
	if (!line)
		return (free_all(&str));
	str = get_right_line(str);
	return (line);
}
