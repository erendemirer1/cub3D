/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoker <asoker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 00:40:16 by asoker            #+#    #+#             */
/*   Updated: 2024/08/25 13:04:06 by asoker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	*ft_calloc(unsigned int count, unsigned int size)
{
	void			*ptr;
	unsigned int	i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (!str)
		return (0);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	str[len1 + len2] = 0;
	return (str);
}

static int	fornorm(char *str, char **arr, int i, int k)
{
	int	j;

	j = 0;
	while (str[i])
	{
		while (str[i] == ',')
		{
			if (str[i + 1] == ',' || str[0] == ',')
			{
				arr[j] = 0;
				freesplit(arr);
				return (0);
			}
			i++;
		}
		k = i;
		while (str[i] && str[i] != ',')
			i++;
		if (i > k)
			arr[j++] = ft_substr(str, k, i - k);
	}
	arr[j] = 0;
	return (1);
}

char	**ft_split2(char *str)
{
	char	**arr;
	int		i;
	int		k;

	arr = (char **)malloc((ft_strlen(str) + 1) * sizeof(char *));
	if (!arr)
		return (0);
	i = 0;
	k = 0;
	if (!fornorm(str, arr, i, k))
		return (0);
	return (arr);
}
