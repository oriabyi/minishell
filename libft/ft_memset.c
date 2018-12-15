/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:27:35 by oriabyi           #+#    #+#             */
/*   Updated: 2017/11/24 18:09:36 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	char *temp;

	if (!memptr)
		return (NULL);
	if (!num)
		return (memptr);
	temp = (char *)memptr;
	while (num-- != 0)
		*temp++ = (char)val;
	return (memptr);
}
