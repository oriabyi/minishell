/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 14:39:45 by oriabyi           #+#    #+#             */
/*   Updated: 2017/11/27 17:16:32 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*newone;

	if (!alst || !*alst)
		return ;
	newone = *alst;
	*alst = NULL;
	del(newone->content, newone->content_size);
	free(newone);
	newone = NULL;
	return ;
}
