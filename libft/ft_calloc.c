/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facelik <facelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:36:18 by facelik           #+#    #+#             */
/*   Updated: 2025/06/03 18:46:52 by facelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*newarr;

	newarr = malloc(sizeof(char) * (nmemb * size));
	if (!newarr)
		return (NULL);
	ft_bzero(newarr, nmemb * size);
	return ((void *)newarr);
}
