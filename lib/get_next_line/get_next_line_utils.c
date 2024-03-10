/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:53:04 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/15 09:53:04 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*gnl_memcpy(void *dest, void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(((gnl_strlen(s1) + gnl_strlen(s2)) + 1) * sizeof(char));
	if (!!str)
	{
		gnl_memcpy(str, s1, gnl_strlen(s1));
		gnl_memcpy(str + gnl_strlen(s1), s2, gnl_strlen(s2));
		str[gnl_strlen(s1) + gnl_strlen(s2)] = '\0';
	}
	free(s1);
	return (str);
}

char	*gnl_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[gnl_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (0);
	i = 0;
	if (gnl_strlen(s + start) < len)
		sub = malloc(gnl_strlen(s + start) * sizeof(char) + 1);
	else
		sub = malloc(len * sizeof(char) + 1);
	if (sub)
	{
		while (start + i < gnl_strlen(s) && i < len)
		{
			sub[i] = s[start + i];
			i++;
		}
		sub[i] = '\0';
	}
	return (sub);
}
