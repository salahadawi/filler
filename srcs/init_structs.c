/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:02:34 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/09 16:16:52 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_filler	*init_filler(void)
{
	t_filler *filler;

	filler = (t_filler*)ft_memalloc(sizeof(t_filler));
	return (filler);
}

int			**init_heatmap(t_filler *filler)
{
	size_t	i;
	size_t	j;
	int		**heatmap;

	heatmap = (int**)ft_memalloc(sizeof(int*) * filler->map_height);
	i = 0;
	while (i < filler->map_height)
	{
		heatmap[i] = (int*)ft_memalloc(sizeof(int) * filler->map_width);
		j = 0;
		while (j < filler->map_width)
			heatmap[i][j++] = INT_MAX;
		i++;
	}
	return (heatmap);
}

int			init_map(t_filler *filler)
{
	size_t	i;
	char	*line;
	char	**map_info;

	if (get_next_line(0, &line) != 1)
		return (handle_error(ERROR_INVALID_MAP));
	map_info = ft_strsplit(line, ' ');
	free(line);
	if (check_map_info(map_info) == -1)
	{
		free_2d_array(map_info);
		return (handle_error(ERROR_INVALID_MAP));
	}
	filler->map_height = ft_atoi(map_info[1]);
	filler->map_width = ft_atoi(map_info[2]);
	free_2d_array(map_info);
	if (filler->map)
		return (0);
	filler->map = (char**)ft_memalloc(sizeof(char *) * filler->map_height);
	i = 0;
	while (i < filler->map_height)
		filler->map[i++] = (char*)ft_memalloc(filler->map_width + 1);
	return (0);
}

int			init_piece(t_filler *filler)
{
	char *line;
	char **piece_size;

	if (get_next_line(0, &line) != 1)
		return (handle_error(ERROR_INVALID_PIECE));
	piece_size = ft_strsplit(line, ' ');
	free(line);
	if (check_piece_info(piece_size) == -1)
	{
		free_2d_array(piece_size);
		return (handle_error(ERROR_INVALID_PIECE));
	}
	filler->piece.height = ft_atoi(piece_size[1]);
	filler->piece.width = ft_atoi(piece_size[2]);
	free_2d_array(piece_size);
	filler->piece.token = (char**)ft_memalloc(sizeof(char*)
		* filler->piece.height);
	return (0);
}

t_moves		*new_move(int x, int y)
{
	t_moves *move;

	move = (t_moves*)ft_memalloc(sizeof(t_moves));
	move->x = x;
	move->y = y;
	move->next = NULL;
	return (move);
}
