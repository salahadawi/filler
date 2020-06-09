/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:44:39 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/09 16:15:22 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		main(void)
{
	t_filler *filler;

	filler = init_filler();
	if (get_player_id(filler) == -1)
	{
		free_memory(filler);
		return (-1);
	}
	while (1)
	{
		if (parse_input(filler) == -1)
			break ;
		if (place_piece(filler) == -1)
		{
			free_piece(filler);
			break ;
		}
		free_piece(filler);
	}
	free_memory(filler);
	return (0);
}
