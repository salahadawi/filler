/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:09:37 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/09 16:15:45 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		find_first_valid(t_filler *filler, int *y_coord, int *x_coord)
{
	size_t	col;
	size_t	row;

	row = 0;
	while (row < filler->map_height - filler->piece.piece_height + 1)
	{
		col = 0;
		while (col < filler->map_width - filler->piece.piece_width + 1)
		{
			if (check_move_valid(filler, row - filler->piece.offset_y,
				col - filler->piece.offset_x))
			{
				*y_coord = row - filler->piece.offset_y;
				*x_coord = col - filler->piece.offset_x;
				return (1);
			}
			col++;
		}
		row++;
	}
	return (-1);
}
