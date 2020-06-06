/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 14:43:18 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/06 14:43:43 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"
#include <stdio.h>///
#include <fcntl.h>///

int fdebug;///

void	debug_print_map(t_filler *filler)///	
{
	size_t	i = 0;
	
	fdebug = open(DEBUG_MAP, O_WRONLY|O_TRUNC);
	while (i < filler->map_height)
	{
		ft_fprintf(fdebug, "%s\n", filler->map[i]);
		i++;
	}
	close(fdebug);
}

void	debug_print_line(char *message)///
{
	fdebug = open(DEBUG_LINE, O_WRONLY|O_APPEND);
	ft_fprintf(fdebug, "%s\n", message);
	close(fdebug);
}

void	debug_print_piece(t_filler *filler)///
{
	size_t	i = 0;
	
	fdebug = open(DEBUG_PIECE, O_WRONLY|O_APPEND);
	ft_fprintf(fdebug, "Piece %d %d:\n", filler->piece.height, filler->piece.width);
	while (i < filler->piece.height)
	{
		ft_fprintf(fdebug, "%s\n", filler->piece.token[i]);
		i++;
	}
	close(fdebug);
}