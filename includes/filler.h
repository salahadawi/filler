/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:44:52 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/04 21:26:49 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"

/*
** Gameplay defines
*/

# define PLAYER_1_SYMBOL X
# define PLAYER_2_SYMBOL O

/*
** Error messages
*/
# define ERROR_PLAYER_ID "Reading player id failed"


typedef struct	s_player
{
	int			player_id;
}				t_player;

typedef struct	s_filler
{
	//t_player	*s_player;
	int			player_id;
	char		**map;
	size_t		map_width;
	size_t		map_height;
	char		*piece;
}				t_filler;

void		handle_error(char *message);
void		get_player_id(t_filler *filler);
t_filler	*init_filler(void);

#endif