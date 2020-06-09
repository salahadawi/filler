/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:10:56 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/09 16:15:18 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		place_piece(t_filler *filler)
{
	int		y;
	int		x;

	get_piece_dimensions(filler);
	make_map_heatmap(filler);
	find_valid_moves(filler);
	if (!filler->valid_moves)
	{
		free_moves(filler);
		free_heatmap(filler);
		ft_printf("0 0\n");
		return (-1);
	}
	score_moves(filler);
	heatmap_algorithm(filler, &y, &x);
	ft_printf("%d %d\n", y, x);
	free_moves(filler);
	free_heatmap(filler);
	return (0);
}
