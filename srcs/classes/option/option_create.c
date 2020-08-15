/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 05:10:42 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/27 20:45:09 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_option	*option_create(void)
{
	t_option	*self;

	self = (t_option *)ft_xmemalloc(sizeof(t_option));
	self->routes = heap_create();
	return (self);
}
