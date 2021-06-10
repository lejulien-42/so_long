/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 00:35:11 by lejulien          #+#    #+#             */
/*   Updated: 2021/06/10 15:30:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		allocplace;
	char	*writeptr;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	allocplace = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(s3 = malloc(allocplace * sizeof(char))))
		return (0);
	writeptr = s3;
	while (*s1 != '\0')
		*writeptr++ = *s1++;
	while (*s2 != '\0')
		*writeptr++ = *s2++;
	*writeptr++ = '\0';
	return (s3);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(src) + 1;
	if (!(dest = (char *)malloc(size * sizeof(char))))
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

