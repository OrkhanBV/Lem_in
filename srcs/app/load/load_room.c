/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:19:19 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/27 20:46:14 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline t_bool	load_room_parse(t_app *self, t_room *room)
{
	char	*line;

	line = self->line;
	if (parse_str(&line, &room->name, "- \n") &&
		parse_skip(&line, " ") &&
		parse_int(&line, &room->coord_x) &&
		parse_skip(&line, " ") &&
		parse_int(&line, &room->coord_y) &&
		parse_skip(&line, "\n") &&
		parse_none(&line))
		return (TRUE);
	return (FALSE);
}

static inline t_bool	load_room_insert(t_app *self, t_room *room)
{
	if (self->signal_start && self->signal_end)
		return (FALSE);
	if (ft_snprintf(self->coord, sizeof(self->coord) - 1,
		"x=%d, y=%d", room->coord_x, room->coord_y) &&
		room->name[0] != 'L' &&
		room->coord_x >= 0 &&
		room->coord_y >= 0 &&
		hashtab_insert(self->coords, self->coord, NULL) &&
		hashtab_insert(self->rooms, room->name, room))
	{
		if (self->signal_start)
		{
			self->room_start = room;
			self->signal_start = FALSE;
		}
		else if (self->signal_end)
		{
			self->room_end = room;
			self->signal_end = FALSE;
		}
		else
			list_push_back(self->links, link_create(&room->in, &room->out, 0));
		return (TRUE);
	}
	return (FALSE);
}

t_bool					load_room(t_app *self)
{
	t_room	*room;

	room = room_create();
	if (!load_room_parse(self, room))
	{
		room_destroy(&room);
		return (FALSE);
	}
	if (!load_room_insert(self, room))
	{
		room_destroy(&room);
		app_error(self);
	}
	return (TRUE);
}
