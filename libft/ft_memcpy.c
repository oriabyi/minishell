/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:27:35 by oriabyi           #+#    #+#             */
/*   Updated: 2017/11/24 18:32:07 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	unsigned	char *temp;
	unsigned	char *sh;

	if (num == 0 || dst == src)
		return (dst);
	temp = (unsigned char *)dst;
	sh = (unsigned char *)src;
	while (num-- != 0)
		*temp++ = *sh++;
	return (dst);
}
