/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:06:16 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/09 16:15:33 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		get_piece(t_filler *filler)
{
	size_t	i;

	if (init_piece(filler) == -1)
		return (-1);
	i = 0;
	while (i < filler->piece.height)
	{
		if (get_next_line(0, &filler->piece.token[i++]) != 1)
			return (handle_error(ERROR_INVALID_PIECE));
	}
	if (!check_piece_valid(filler))
		return (handle_error(ERROR_INVALID_PIECE));
	return (0);
}

int		check_piece_info(char **piece_info)
{
	int i;

	i = 0;
	while (piece_info[i])
		i++;
	if (i != 3)
		return (-1);
	if (!ft_strequ("Piece", piece_info[0]))
		return (-1);
	if (!atoi(piece_info[1]) || !atoi(piece_info[2]))
		return (-1);
	return (0);
}

int		check_piece_valid(t_filler *filler)
{
	size_t i;

	i = 0;
	while (i < filler->piece.height)
		if (ft_strlen(filler->piece.token[i++]) != filler->piece.width)
			return (0);
	return (1);
}
