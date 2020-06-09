/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:44:52 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/09 15:56:49 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include <limits.h>

/*
** VM/Gameplay defines
*/

# define PLAYER_1_SYMBOL 'O'
# define PLAYER_2_SYMBOL 'X'
# define VM_PLAYER1 "$$$ exec p1"
# define VM_PLAYER2 "$$$ exec p2"

/*
** Error messages
*/

# define ERROR_READ_PLAYER_ID "Reading player id failed"
# define ERROR_INVALID_PLAYER_ID "Invalid player id"
# define ERROR_READ_MAP "Reading map failed"
# define ERROR_INVALID_MAP "Invalid map"
# define ERROR_INVALID_PIECE "Invalid piece"

/*
** Debug
*/

# define DEBUG_OUTPUT "debug.txt"
# define DEBUG_VM_OUTPUT "debug_vm.txt"
# define DEBUG_PIECE "debug_piece.txt"
# define DEBUG_LINE "debug_line.txt"
# define DEBUG_MAP "debug_map.txt"

typedef struct		s_moves
{
	int				x;
	int				y;
	int				score;
	struct s_moves	*next;
}					t_moves;

typedef struct		s_piece
{
	char			**token;
	size_t			offset_y;
	size_t			offset_x;
	size_t			width;
	size_t			height;
	size_t			piece_width;
	size_t			piece_height;
}					t_piece;

typedef struct		s_filler
{
	char			player_symbol;
	char			opponent_symbol;
	char			**map;
	int				**heatmap;
	size_t			map_width;
	size_t			map_height;
	t_piece			piece;
	t_moves			*valid_moves;
}					t_filler;

#endif
