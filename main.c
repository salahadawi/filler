/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:44:39 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/05 16:27:09 by sadawi           ###   ########.fr       */
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

	filler->player_id = ft_atoi(ft_strchr(line, 'p') + 1);
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

void	init_map(t_filler *filler)
{
	size_t	i;
	char 	*line;
	char 	**size;

	get_next_line(0, &line);
	if (filler->map)
	{
		free(line);
		return ;
	}
	size = ft_strsplit(line, ' ');
	filler->map_height = ft_atoi(size[1]);
	filler->map_width = ft_atoi(size[2]);
	free_2d_array(size);
	filler->map = (char**)ft_memalloc(sizeof(char *) * filler->map_height);
	i = 0;
	while (i < filler->map_height)
		filler->map[i++] = (char*)ft_memalloc(sizeof(char) * filler->map_width);
}

void	skip_coordinates(void)
{
	char *line;

	get_next_line(0, &line);
	free(line);
}

void	get_map(t_filler *filler)
{
	char	*line;
	size_t	i;
	// Add check that map is of correct width and height. If yes, next line should be Piece.
	init_map(filler);
	skip_coordinates();
	i = 0;
	while (i < filler->map_height)
	{
		get_next_line(0, &line);
		ft_strcpy(filler->map[i++], ft_strchr(line, ' ') + 1);
		free(line);
	}
	debug_print_map(filler);//
}

void	init_piece(t_filler *filler)
{
	char *line;
	char **piece_size;

	get_next_line(0, &line);
	piece_size = ft_strsplit(line, ' ');
	filler->piece.height = ft_atoi(piece_size[1]);
	filler->piece.width = ft_atoi(piece_size[2]);
	free_2d_array(piece_size);
	filler->piece.token = (char**)ft_memalloc(sizeof(char *) * filler->piece.height);
}

void	get_piece(t_filler *filler)
{
	size_t	i;

	init_piece(filler);
	i = 0;
	while (i < filler->piece.height)
		get_next_line(0, &filler->piece.token[i++]);
	debug_print_piece(filler);//
}

void	parse_input(t_filler *filler)
{
	get_map(filler);
	get_piece(filler);
	/*filler->piece = line[numbers]
	while i < piece_size[1]
	{
		filler->piece[i] = line;
	}*/
}

int		main(void)
{
	t_filler *filler;
	char *line;
	
	filler = init_filler();
	if (get_player_id(filler) == -1)
		return (-1);
	while (1)
	{
		parse_input(filler);
		//place_piece(filler);
	}
	while (get_next_line(0, &line) > 0)
	{
		free(line);
	}
	return (0);
}
