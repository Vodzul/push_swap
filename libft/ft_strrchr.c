/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facelik <facelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:34:10 by facelik           #+#    #+#             */
/*   Updated: 2025/05/28 17:59:58 by facelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = ft_strlen(s);
	if (ch == '\0')
		return ((char *)(s + i));
	while (i > 0)
	{
		i--;
		if ((unsigned char)s[i] == ch)
			return ((char *)(s + i));
	}
	return (NULL);
}
