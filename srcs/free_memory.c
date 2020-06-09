/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:00:10 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/09 16:15:43 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_memory(t_filler *filler)
{
	size_t i;

	i = 0;
	while (i < filler->map_height)
		free(filler->map[i++]);
	free(filler->map);
	free(filler);
}

void	free_2d_array(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_moves(t_filler *filler)
{
	t_moves *tmp;

	while (filler->valid_moves)
	{
		tmp = filler->valid_moves->next;
		free(filler->valid_moves);
		filler->valid_moves = tmp;
	}
}

void	free_heatmap(t_filler *filler)
{
	size_t i;

	i = 0;
	while (i < filler->map_height)
		free(filler->heatmap[i++]);
	free(filler->heatmap);
	filler->heatmap = NULL;
}

void	free_piece(t_filler *filler)
{
	size_t i;

	i = 0;
	while (i < filler->piece.height)
		free(filler->piece.token[i++]);
	free(filler->piece.token);
	ft_memset((void*)&filler->piece, 0, sizeof(filler->piece));
}
