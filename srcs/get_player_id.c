/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:09:37 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/09 16:15:31 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		get_player_id(t_filler *filler)
{
	char *line;

	if (get_next_line(0, &line) != 1)
		return (handle_error(ERROR_READ_PLAYER_ID));
	if (!ft_strnequ(VM_PLAYER1, line, 11) && !ft_strnequ(VM_PLAYER2, line, 11))
	{
		free(line);
		return (handle_error(ERROR_INVALID_PLAYER_ID));
	}
	if (ft_atoi(ft_strchr(line, 'p') + 1) == 1)
	{
		filler->player_symbol = PLAYER_1_SYMBOL;
		filler->opponent_symbol = PLAYER_2_SYMBOL;
	}
	else
	{
		filler->player_symbol = PLAYER_2_SYMBOL;
		filler->opponent_symbol = PLAYER_1_SYMBOL;
	}
	free(line);
	return (0);
}
