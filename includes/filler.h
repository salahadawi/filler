/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:44:52 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/05 16:24:16 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"

/*
** VM/Gameplay defines
*/

# define PLAYER_1_SYMBOL X
# define PLAYER_2_SYMBOL O
# define VM_PLAYER1 "$$$ exec p1"
# define VM_PLAYER2 "$$$ exec p2"

/*
** Error messages
*/

# define ERROR_READ_PLAYER_ID "Reading player id failed"
# define ERROR_INVALID_PLAYER_ID "Invalid player id"
# define ERROR_READ_MAP "Reading map failed"
# define ERROR_INVALID_MAP "Invalid map"

/*
** Debug
*/

# define DEBUG_OUTPUT "debug.txt"
# define DEBUG_VM_OUTPUT "debug_vm.txt"
# define DEBUG_PIECE "debug_piece.txt"
# define DEBUG_LINE "debug_line.txt"
# define DEBUG_MAP "debug_map.txt"

typedef struct	s_player
{
	int			player_id;
}				t_player;

typedef struct	s_piece
{
	char		**token;
	size_t		width;
	size_t		height;
}				t_piece;

typedef struct	s_filler
{
	//t_player	*s_player;
	int				player_id;
	char			**map;
	size_t			map_width;
	size_t			map_height;
	t_piece			piece;
}					t_filler;

#endif