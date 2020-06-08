/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 14:43:18 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/08 15:33:28 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"
#include <stdio.h>///
#include <fcntl.h>///

int fdebug;///

void	debug_print_map(t_filler *filler)///	
{
	size_t	i = 0;
	
	fdebug = open(DEBUG_MAP, O_WRONLY|O_APPEND);
	ft_fprintf(fdebug, "MAP: \n");
	while (i < filler->map_height)
		ft_fprintf(fdebug, "%s\n", filler->map[i++]);
	i = 0;
	ft_fprintf(fdebug, "\nPIECE: \n");
	while (i < filler->piece.height)
		ft_fprintf(fdebug, "%s\n", filler->piece.token[i++]);

	ft_fprintf(fdebug, "y: %d, x: %d\n", filler->piece.offset_y, filler->piece.offset_x);
	ft_fprintf(fdebug, "PIECE SIZE: h: %d, w: %d", filler->piece.piece_height, filler->piece.piece_width);
	ft_fprintf(fdebug, "\n");
	close(fdebug);
}

void	debug_print_line(char *message)///
{
	fdebug = open(DEBUG_LINE, O_WRONLY|O_APPEND);
	ft_fprintf(fdebug, "%s\n", message);
	close(fdebug);
}

void	debug_print_line_heatmap(int *line, int size)///
{
	fdebug = open(DEBUG_LINE, O_WRONLY|O_APPEND);
	for (int i = 0; i < size; i++)
		ft_fprintf(fdebug, "%d ", line[i]);
	ft_fprintf(fdebug, "\n");
	close(fdebug);
}

void	debug_print_piece(t_filler *filler)///
{
	size_t	i = 0;
	
	fdebug = open(DEBUG_PIECE, O_WRONLY|O_APPEND);
	ft_fprintf(fdebug, "Piece %d %d: Player: %c\n", filler->piece.height, filler->piece.width, filler->player_symbol);
	while (i < filler->piece.height)
	{
		ft_fprintf(fdebug, "%s\n", filler->piece.token[i]);
		i++;
	}
	close(fdebug);
}