/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:16:36 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/27 20:45:00 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline t_bool	load_number_parse(t_app *self)
{
	char	*line;

	line = self->line;
	if (parse_int(&line, &self->number) &&
		parse_skip(&line, "\n") &&
		parse_none(&line))
		return (TRUE);
	return (FALSE);
}

t_bool					load_number(t_app *self)
{
	if (self->signal_start || self->signal_end)
		app_error(self);
	if (!load_number_parse(self))
		app_error(self);
	if (self->number <= 0)
		app_error(self);
	return (TRUE);
}
