/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numodgt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:34:37 by oriabyi           #+#    #+#             */
/*   Updated: 2017/11/27 15:44:04 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numodgt(long long n)
{
	int			counter;

	counter = 1;
	if (!n)
		return (1);
	while (n && counter++)
		n /= 10;
	return (counter - 1);
}
