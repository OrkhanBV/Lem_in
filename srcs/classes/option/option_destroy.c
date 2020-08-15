/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 05:12:11 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/25 23:14:27 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	option_destroy(t_option **aself)
{
	if (aself && *aself)
	{
		heap_clean((*aself)->routes, &list_destroy);
		heap_destroy(&(*aself)->routes);
		ft_memdel((void **)aself);
	}
}
