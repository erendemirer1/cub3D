/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoker <asoker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:01:00 by asoker            #+#    #+#             */
/*   Updated: 2024/08/20 03:35:03 by asoker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/utils.h"

void	*ft_free_stash(char **stash, int create_line)
{
	char	*line;

	if (!*stash)
		return (0);
	if (create_line == 0)
	{
		if (*stash)
		{
			free(*stash);
			*stash = 0;
		}
		return (0);
	}
	else if (create_line == 1)
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = 0;
		return (line);
	}
	return (0);
}
