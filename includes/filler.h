/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:44:52 by sadawi            #+#    #+#             */
/*   Updated: 2020/06/09 15:58:34 by sadawi           ###   ########.fr       */
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

int					handle_error(char *message);

int					get_player_id(t_filler *filler);

t_filler			*init_filler(void);

void				free_2d_array(char **arr);

int					check_map_info(char **map_info);

int					init_map(t_filler *filler);

int					skip_coordinates(void);

int					check_map_line_valid(t_filler *filler, char *line);

int					check_map_contains_players(t_filler *filler);

int					get_map(t_filler *filler);

int					check_piece_info(char **piece_info);

int					init_piece(t_filler *filler);

int					check_piece_valid(t_filler *filler);

int					get_piece(t_filler *filler);

int					parse_input(t_filler *filler);

void				get_y_offset(t_filler *filler);

void				get_x_offset(t_filler *filler);

void				get_piece_width(t_filler *filler);

void				get_piece_height(t_filler *filler);

void				get_piece_dimensions(t_filler *filler);

int					check_move_valid(t_filler *filler, int y, int x);

int					find_first_valid(t_filler *filler,
								int *y_coord, int *x_coord);

t_moves				*new_move(int x, int y);

t_moves				*add_valid_move(t_filler *filler,
							int col, int row, t_moves *tmp);

void				find_valid_moves(t_filler *filler);

void				free_moves(t_filler *filler);

int					**init_heatmap(t_filler *filler);

int					ft_abs(int n);

void				heatmap(t_filler *filler, int x, int y);

void				make_map_heatmap(t_filler *filler);

void				free_heatmap(t_filler *filler);

void				get_move_score(t_filler *filler, t_moves *move);

void				score_moves(t_filler *filler);

void				heatmap_algorithm(t_filler *filler, int *y, int *x);

int					place_piece(t_filler *filler);

void				free_piece(t_filler *filler);

void				free_memory(t_filler *filler);

#endif
