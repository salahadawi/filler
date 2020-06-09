/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece_stats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:07:01 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/09 16:15:35 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_y_offset(t_filler *filler)
{
	size_t	i;

	i = 0;
	while (filler->piece.token[i])
	{
		if (!ft_strchr(filler->piece.token[i++], '*'))
			filler->piece.offset_y++;
		else
			break ;
	}
}

void	get_x_offset(t_filler *filler)
{
	size_t row;
	size_t col;

	col = 0;
	while (col < filler->piece.width)
	{
		row = 0;
		while (row < filler->piece.height)
		{
			if (filler->piece.token[row][col] == '*')
				return ;
			row++;
		}
		filler->piece.offset_x++;
		col++;
	}
}

void	get_piece_width(t_filler *filler)
{
	size_t	row;
	size_t	col;

	col = 0;
	while (col < filler->piece.width)
	{
		row = 0;
		while (row < filler->piece.height)
		{
			if (filler->piece.token[row][col] == '*')
			{
				filler->piece.piece_width++;
				break ;
			}
			row++;
		}
		col++;
	}
}

void	get_piece_height(t_filler *filler)
{
	size_t	row;

	row = 0;
	while (row < filler->piece.height)
	{
		if (ft_strchr(filler->piece.token[row], '*'))
			filler->piece.piece_height++;
		row++;
	}
}

void	get_piece_dimensions(t_filler *filler)
{
	get_y_offset(filler);
	get_x_offset(filler);
	get_piece_width(filler);
	get_piece_height(filler);
}
