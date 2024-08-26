/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edemirer <edemirer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 00:39:01 by asoker            #+#    #+#             */
/*   Updated: 2024/08/24 15:28:30 by edemirer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	**ft_split(char *str, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		k;

	arr = (char **)malloc((ft_strlen(str) + 1) * sizeof(char *));
	if (!arr)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		k = i;
		while (str[i] && str[i] != c)
			i++;
		if (i > k)
		{
			arr[j] = ft_substr(str, k, i - k);
			j++;
		}
	}
	arr[j] = 0;
	return (arr);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	unsigned char	*dst_c;
	unsigned char	*src_c;

	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	while (n--)
		*dst_c++ = *src_c++;
	return (dst);
}
