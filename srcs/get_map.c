/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:04:25 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/09 16:15:36 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		get_map(t_filler *filler)
{
	char	*line;
	size_t	i;

	if (init_map(filler) == -1)
		return (-1);
	if (skip_coordinates() == -1)
		return (-1);
	i = 0;
	while (i < filler->map_height)
	{
		if (get_next_line(0, &line) != 1)
			return (handle_error(ERROR_INVALID_MAP));
		if (!check_map_line_valid(filler, line))
		{
			free(line);
			return (handle_error(ERROR_INVALID_MAP));
		}
		ft_strcpy(filler->map[i++], ft_strchr(line, ' ') + 1);
		free(line);
	}
	if (!check_map_contains_players(filler))
		return (handle_error(ERROR_INVALID_MAP));
	return (0);
}

int		check_map_info(char **map_info)
{
	int i;

	i = 0;
	while (map_info[i])
		i++;
	if (i != 3)
		return (-1);
	if (!ft_strequ("Plateau", map_info[0]))
		return (-1);
	if (!atoi(map_info[1]) || !atoi(map_info[2]))
		return (-1);
	return (0);
}

int		skip_coordinates(void)
{
	char *line;

	if (get_next_line(0, &line) != 1)
		return (handle_error(ERROR_INVALID_MAP));
	free(line);
	return (0);
}

int		check_map_line_valid(t_filler *filler, char *line)
{
	char *row_start_ptr;

	row_start_ptr = ft_strchr(line, ' ');
	if (!row_start_ptr)
		return (0);
	row_start_ptr++;
	if (ft_strlen(row_start_ptr) != filler->map_width)
		return (0);
	return (1);
}

int		check_map_contains_players(t_filler *filler)
{
	size_t	i;
	int		player_x_found;
	int		player_o_found;

	i = 0;
	player_x_found = 0;
	player_o_found = 0;
	while (i < filler->map_height)
	{
		if (ft_strchr(filler->map[i], 'X'))
			player_x_found = 1;
		if (ft_strchr(filler->map[i], 'O'))
			player_o_found = 1;
		i++;
	}
	return (player_x_found && player_o_found);
}
