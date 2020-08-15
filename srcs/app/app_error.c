/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 23:46:23 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/25 23:14:37 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	app_error(t_app *self)
{
	if (self)
		ft_printf_fd(STDERR_FILENO, "ERROR\n");
	ft_xexit(EXIT_FAILURE);
}
