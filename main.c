/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:44:39 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/06 17:22:20 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"
#include <stdio.h>///
#include <fcntl.h>///

int		handle_error(char *message)
{
	//ft_fprintf(2, "Error: %s", message);
	//open only for debug
	int fd = open(DEBUG_OUTPUT, O_WRONLY);///
	ft_fprintf(fd, "%s\n", message);///
	ft_fprintf(2, "%s\n", message);
	close(fd);///
	//free memory
	return (-1);
}

int		get_player_id(t_filler *filler)
{
	char *line;

	if (get_next_line(0, &line) == -1)
		return handle_error(ERROR_READ_PLAYER_ID);
	if (!ft_strnequ(VM_PLAYER1, line, 11) && !ft_strnequ(VM_PLAYER2, line, 11))
		return handle_error(ERROR_INVALID_PLAYER_ID);

	if (ft_atoi(ft_strchr(line, 'p') + 1) == '1')
	{
		filler->player_symbol = PLAYER_1_SYMBOL;
		filler->opponent_symbol = PLAYER_2_SYMBOL;
	}
	else
	{
		filler->player_symbol = PLAYER_2_SYMBOL;
		filler->opponent_symbol = PLAYER_1_SYMBOL;
	}
	return (0);
}

t_filler	*init_filler()
{
	t_filler *filler;

	filler = (t_filler*)ft_memalloc(sizeof(t_filler));
	return (filler);
}

void	free_2d_array(char **arr)
{
	int i;

	i = 0;
	while(arr[i])
		free(arr[i++]);
	free(arr);
}

int		check_map_info(char **map_info)
{
	int i;

	i = 0;
	debug_print_line("***\n");
	while (map_info[i])
	{
		debug_print_line(map_info[i]);
		i++;
	}
	if (i != 3)
		return (-1);
	if (!ft_strequ("Plateau", map_info[0]))
		return (-1);
	if (!atoi(map_info[1]) || !atoi(map_info[2]))
		return (-1);
	return (0);
}

int		init_map(t_filler *filler)
{
	size_t	i;
	char 	*line;
	char 	**map_info;

	get_next_line(0, &line);
	if (!line)
	{
		handle_error(GOT_NULL_FROM_VM);
		return (-1);
	}
	debug_print_line("*************8");
	debug_print_line(line);
	map_info = ft_strsplit(line, ' ');
	if (check_map_info(map_info) == -1)
		return handle_error(ERROR_INVALID_MAP);
	filler->map_height = ft_atoi(map_info[1]);
	filler->map_width = ft_atoi(map_info[2]);
	free_2d_array(map_info);
	if (filler->map)
	{
		free(line);
		return (0);
	}
	filler->map = (char**)ft_memalloc(sizeof(char *) * filler->map_height);
	i = 0;
	while (i < filler->map_height)
		filler->map[i++] = (char*)ft_memalloc(sizeof(char) * filler->map_width);
	return (0);
}

void	skip_coordinates(void)
{
	char *line;

	get_next_line(0, &line);
	free(line);
}

int		get_map(t_filler *filler)
{
	char	*line;
	size_t	i;
	// Add check that map is of correct width and height. If yes, next line should be Piece.
	if (init_map(filler) == -1)
		return (-1);
	skip_coordinates();
	i = 0;
	while (i < filler->map_height)
	{
		get_next_line(0, &line);
		ft_strcpy(filler->map[i++], ft_strchr(line, ' ') + 1);
		free(line);
	}
	debug_print_map(filler);//
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

int		init_piece(t_filler *filler)
{
	char *line;
	char **piece_size;

	get_next_line(0, &line);
	piece_size = ft_strsplit(line, ' ');
	if (check_piece_info(piece_size) == -1)
		return handle_error(ERROR_INVALID_PIECE);
	filler->piece.height = ft_atoi(piece_size[1]);
	filler->piece.width = ft_atoi(piece_size[2]);
	free_2d_array(piece_size);
	filler->piece.token = (char**)ft_memalloc(sizeof(char *) * filler->piece.height);
	return (0);
}

int		get_piece(t_filler *filler)
{
	size_t	i;

	if (init_piece(filler) == -1)
		return (-1);
	i = 0;
	while (i < filler->piece.height)
		get_next_line(0, &filler->piece.token[i++]);
	debug_print_piece(filler);//
	return (0);
}

int		parse_input(t_filler *filler)
{
	if (get_map(filler) == -1)
		return (-1);
	if (get_piece(filler) == -1)
		return (-1);
	return (0);
}

void	get_y_offset(t_filler *filler)
{
	size_t	i;

	i = 0;
	while (filler->piece.token[i])
	{
		if (!ft_strchr(filler->piece.token[i++], '*'))
			filler->piece.offset_y++;
		else
			break;
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
	size_t	row_width;

	row = 0;
	while (row < filler->piece.height)
	{
		row_width = 0;
		col = 0;
		while (col < filler->piece.width)
		{	
			if (filler->piece.token[row][col] == '*')
				row_width++;
			col++;
		}
		if (row_width > filler->piece.piece_width)
			filler->piece.piece_width = row_width;
		row++;
	}
}

void	get_piece_height(t_filler *filler)
{
	size_t	row;
	size_t	col;
	size_t	col_height;

	col = 0;
	while (col < filler->piece.width)
	{
		col_height = 0;
		row = 0;
		while (row < filler->piece.height)
		{	
			if (filler->piece.token[row][col] == '*')
				col_height++;
			row++;
		}
		if (col_height > filler->piece.piece_height)
			filler->piece.piece_height = col_height;
		col++;
	}
}

void	get_piece_dimensions(t_filler *filler)
{
	//int	i;
	//int	j;

	get_y_offset(filler);
	get_x_offset(filler);
	get_piece_width(filler);
	get_piece_height(filler);
	
	debug_print_line(ft_sprintf("y: %d, x: %d", filler->piece.offset_y, filler->piece.offset_x));
	debug_print_line(ft_sprintf("SIZE: h: %d, w: %d", filler->piece.piece_height, filler->piece.piece_width));
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
			//debug_print_line(ft_sprintf("COORDINATES: %d %d %d\n", col, row, overlap_count));
			if (filler->piece.token[row][col] == '*')
			{
				if (filler->map[y + row][x + col] == filler->opponent_symbol)
				{
					return (0);
				}
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

/*
.......
.......
.......
.......

....
.xx.
*/

int		find_first_valid(t_filler *filler, int *y_coord, int *x_coord)
{
	size_t	col;
	size_t	row;
	
	row = 0; //could change this and col to start from [piece height + width] offset area from our squares
	while (row < filler->map_height)
	{
		col = 0;
		while (col < filler->map_width)
		{
			//debug_print_line(ft_sprintf("Checking: %d %d\n", row, col));
			if (check_move_valid(filler, row - filler->piece.offset_y, col - filler->piece.offset_x))
			{
				*y_coord = row -filler->piece.offset_y;
				*x_coord = col - filler->piece.offset_x;
				return (1);
			}
			col++;
		}
		row++;
	}
	return (-1);
}

int		place_piece(t_filler *filler)
{
	int		y;
	int		x;

	get_piece_dimensions(filler);
	if (find_first_valid(filler, &y, &x) == -1)
		return (-1);
	ft_printf("%d %d\n", y, x);
	debug_print_line(ft_sprintf("COORDINATES: %d %d\n", y, x));
	return (0);
}

void	free_piece(t_filler *filler)
{
	size_t i;

	while (i < filler->piece.height)
		free(filler->piece.token[i++]);
	free(filler->piece.token);
}

int		main(void)
{
	t_filler *filler;

	filler = init_filler();
	if (get_player_id(filler) == -1)
		return (-1);
	while (1)
	{
		if (parse_input(filler) == -1)
			break;
		place_piece(filler);
		free_piece(filler);
	}
	//FREE MeMORY!!!!!
	return (0);
}
