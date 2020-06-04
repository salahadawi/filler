/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:44:39 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/04 21:37:21 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"
#include <stdio.h>///
#include <fcntl.h>///

void	handle_error(char *message)
{
	//ft_fprintf(2, "Error: %s", message);
	//open only for debug
	int fd = open("debug", O_WRONLY);///
	ft_fprintf(fd, "%s\n", message);
	close(fd);
	exit(0);
}

void	get_player_id(t_filler *filler)
{
	char *line;
	char *id_pointer;

	if (get_next_line(0, &line) == -1)
		handle_error(ERROR_PLAYER_ID);
	if (!(id_pointer = ft_strchr(line, 'p')))
		handle_error("Invalid player id.");
	filler->player_id = ft_atoi(id_pointer + 1);
	handle_error("yes");
	mäki brb
}

t_filler	*init_filler(void)
{
	t_filler *filler;

	filler = (t_filler*)ft_memalloc(sizeof(t_filler));
	return (filler);
}

void	skip_useless_lines(void)
{
	char *line;

	get_next_line(0, &line);
	free(line);
	get_next_line(0, &line);
	free(line);
}

void	init_map(t_filler *filler)
{
	int		i;
	char 	*line;
	char 	**size;

	get_next_line(0, &line);
	size = ft_strsplit(line, ' ');
	filler->map_height = ft_atoi(size[1]);
	filler->map_width = ft_atoi(size[2]);
	while (*size)
		free((*size)++);
	free(size);
	filler->map = (char**)malloc(sizeof(char *) * filler->map_height);
	i = 0;
	while (i < filler->map_height)
		filler->map[i++] = (char*)malloc(sizeof(char) * filler->map_width);
	handle_error(size[1]);
}

void	parse_input(t_filler *filler)
{
	char *line;

	if (filler->map)
		skip_useless_lines();
	else
		init_map(filler);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Piece"))
			break;
		
	}
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
	
	int fd = open("testi", O_WRONLY);
	filler = init_filler();
	get_player_id(filler);
	ft_fprintf(1, "moi2323");
	while (1)
	{
		parse_input(filler);
		//place_piece(filler);
	}
	while (get_next_line(0, &line) > 0)
	{
		ft_fprintf(fd, "%s\n", line);
		ft_printf("12 14\n");
		free(line);
	}
	ft_fprintf(fd, "\n");
	close(fd);
	ft_printf("3 5\n");
	return (0);
}
