/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_valid_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:08:46 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/09 16:15:46 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_moves	*add_valid_move(t_filler *filler, int col, int row, t_moves *tmp)
{
	if (!tmp)
	{
		tmp = new_move(col - filler->piece.offset_x,
		row - filler->piece.offset_y);
		filler->valid_moves = tmp;
	}
	else
	{
		tmp->next = new_move(col - filler->piece.offset_x,
		row - filler->piece.offset_y);
		tmp = tmp->next;
	}
	return (tmp);
}

void	find_valid_moves(t_filler *filler)
{
	size_t	col;
	size_t	row;
	t_moves *tmp;

	tmp = NULL;
	row = 0;
	while (row < filler->map_height - filler->piece.piece_height + 1)
	{
		col = 0;
		while (col < filler->map_width - filler->piece.piece_width + 1)
		{
			if (check_move_valid(filler, row - filler->piece.offset_y,
				col - filler->piece.offset_x))
				tmp = add_valid_move(filler, col, row, tmp);
			col++;
		}
		row++;
	}
}

int		check_move_valid(t_filler *filler, int y, int x)
{
	size_t	overlap_count;
	size_t	col;
	size_t	row;

	overlap_count = 0;
	row = 0;
	while (row < filler->piece.height)
	{
		col = 0;
		while (col < filler->piece.width && overlap_count < 2)
		{
			if (filler->piece.token[row][col] == '*')
			{
				if (filler->map[y + row][x + col] == filler->opponent_symbol)
					return (0);
				if (filler->map[y + row][x + col] == filler->player_symbol)
					overlap_count++;
			}
			col++;
		}
		row++;
	}
	if (overlap_count == 1)
		return (1);
	return (0);
}
