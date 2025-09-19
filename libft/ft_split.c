/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facelik <facelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:34:39 by facelik           #+#    #+#             */
/*   Updated: 2025/06/23 18:49:50 by facelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countword(char const *s, char c)
{
	int	count;
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
		{
			flag = 1;
			i++;
		}
		if (flag)
			count++;
		flag = 0;
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static void	freearr(char **newarr, int j)
{
	int	k;

	k = 0;
	while (k < j)
		free(newarr[k++]);
	free(newarr);
}

static int	copywords(char **newarr, char const *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			newarr[j++] = ft_substr(s, start, i - start);
			if (!newarr[j - 1])
			{
				freearr(newarr, j);
				return (-1);
			}
		}
	}
	newarr[j] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**newarr;

	if (!s)
		return (NULL);
	newarr = malloc(sizeof(char *) * (countword(s, c) + 1));
	if (!newarr)
		return (NULL);
	if (copywords(newarr, s, c) == -1)
		return (NULL);
	return (newarr);
}
