/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 05:58:54 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/25 23:14:16 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	room_destroy(t_room **aself)
{
	if (aself && *aself)
	{
		ft_strdel(&(*aself)->name);
		ft_memdel((void **)aself);
	}
}
