/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:07:45 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/09 16:15:26 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	heatmap_algorithm(t_filler *filler, int *y, int *x)
{
	t_moves *best_move;
	t_moves *tmp;

	tmp = filler->valid_moves;
	best_move = tmp;
	while (tmp)
	{
		if (tmp->score < best_move->score)
			best_move = tmp;
		tmp = tmp->next;
	}
	*y = best_move->y;
	*x = best_move->x;
}

void	heatmap(t_filler *filler, int x, int y)
{
	size_t	col;
	size_t	row;
	int		value;

	if (!filler->heatmap)
		filler->heatmap = init_heatmap(filler);
	row = 0;
	while (row < filler->map_height)
	{
		col = 0;
		while (col < filler->map_width)
		{
			value = ft_abs(col - x) > ft_abs(row - y)
				? ft_abs(col - x) : ft_abs(row - y);
			if (filler->heatmap[row][col] > value)
				filler->heatmap[row][col] = value;
			col++;
		}
		row++;
	}
}

void	make_map_heatmap(t_filler *filler)
{
	size_t	col;
	size_t	row;

	col = 0;
	row = 0;
	while (row < filler->map_height)
	{
		col = 0;
		while (col < filler->map_width)
		{
			if (filler->map[row][col] == filler->opponent_symbol)
				heatmap(filler, col, row);
			col++;
		}
		row++;
	}
}

void	get_move_score(t_filler *filler, t_moves *move)
{
	size_t col;
	size_t row;

	row = 0;
	while (row < filler->piece.height)
	{
		col = 0;
		while (col < filler->piece.width)
		{
			if (filler->piece.token[row][col] == '*')
				move->score += filler->heatmap[move->y + row][move->x + col];
			col++;
		}
		row++;
	}
	return ;
}

void	score_moves(t_filler *filler)
{
	t_moves *tmp;

	tmp = filler->valid_moves;
	while (tmp)
	{
		get_move_score(filler, tmp);
		tmp = tmp->next;
	}
}
