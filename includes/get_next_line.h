/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:29:46 by cortiz            #+#    #+#             */
/*   Updated: 2023/03/27 13:23:53 by carlosortiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1000

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*get_left_line(char *src);
char	*get_right_line(char *str);
char	*get_all_line(int fd, char *str);
int		has_nl(char *str);
char	*ft_strjoine(char *str1, char *str2);
char	*free_all(char **str1);
size_t	ft_strlene(char *str);

#endif