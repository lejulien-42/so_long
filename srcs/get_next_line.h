/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 00:35:55 by lejulien          #+#    #+#             */
/*   Updated: 2021/06/10 15:30:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_char
{
	char *tobuff;
	char *toline;
}				t_char;

size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *src);
int				get_next_line(int fd, char **line);
t_char			*ft_cut(char *buffer);
char			*ft_read(int fd, char **buffer);
int				ft_hasnl(char *str);
#endif

