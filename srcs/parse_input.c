/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:11:24 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/09 16:15:20 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		parse_input(t_filler *filler)
{
	if (get_map(filler) == -1)
		return (-1);
	if (get_piece(filler) == -1)
		return (-1);
	return (0);
}
