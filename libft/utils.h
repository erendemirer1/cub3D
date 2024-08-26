/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edemirer <edemirer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:36:50 by asoker            #+#    #+#             */
/*   Updated: 2024/08/25 12:25:05 by edemirer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../include/cub3d.h"
# include <stdlib.h>

int		ft_strlen(const char *s);
char	**ft_split2(char *str);
char	**ft_split(char *str, char c);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memcpy(void *dst, const void *src, unsigned int n);
char	*ft_substr(char const *s, unsigned int start, unsigned int len);
char	*ft_strdup(const char *s);
int		ft_strchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	*ft_calloc(unsigned int count, unsigned int size);
char	*ft_strjoin(char const *s1, char const *s2);

#endif