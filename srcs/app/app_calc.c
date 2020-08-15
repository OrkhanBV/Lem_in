/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 00:00:40 by jremarqu          #+#    #+#             */
/*   Updated: 2020/08/15 18:13:14 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			app_calc(t_app *self)
{
	t_option	*last;
	t_option	*best;

	self->paths = list_create();
	self->options = heap_create();
	self->ants = list_create();
	best = NULL;
	while (calc_bellman_ford(self))
	{
		calc_suurballe(self);
		last = calc_option(self);
		heap_insert(self->options, last->steps, last);
		best = heap_peek(self->options);
		if (best->steps < last->steps)
			break ;
	}
	if (best == NULL)
		app_error(self);
	calc_populate(self, best);
}
