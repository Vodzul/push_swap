/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facelik <facelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:28:35 by facelik           #+#    #+#             */
/*   Updated: 2025/06/23 18:53:39 by facelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	istrim(char const s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*newarr;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && istrim(s1[start], set))
		start++;
	end = ft_strlen(s1);
	if (end == 0 || start == end)
		return (ft_strdup(""));
	end--;
	while (end > start && istrim(s1[end], set))
		end--;
	newarr = malloc(end - start + 2);
	if (!newarr)
		return (NULL);
	i = 0;
	while (start <= end)
		newarr[i++] = s1[start++];
	newarr[i] = '\0';
	return (newarr);
}
