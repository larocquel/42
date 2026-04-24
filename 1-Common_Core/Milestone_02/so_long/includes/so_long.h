/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:35:52 by leoaguia          #+#    #+#             */
/*   Updated: 2025/07/07 17:39:32 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/libft.h"

# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>
# include <limits.h>
# include <fcntl.h>

/* ************************************************************************** */
/*   MESSAGES                                                                 */
/* ************************************************************************** */

# define EMPTY			"Error: empty or invalid file!\n"
# define NO_FILE		"Error: no such file or directory:"
# define FORMAT_ERROR	"Error: invlid map format, ensure the file is .ber\n"
# define MAP_SIZE		"Error: invalid map size!\n"
# define MAP_WALLS		"Error: The map is not surrounded by walls!\n"
# define INVALID_CHAR	"Error: There is a invalid character in the map!\n"
# define PATH_ERROR		"Error: No avaiable path!\n"
# define INV_C			"Error: Invalid amount of players, "
# define INV_C2			"exits or collectables!\n"
# define AV_ERROR		"ERROR\nusage: $> ./so_long map.ber\n"

/* ************************************************************************** */
/*   TEXTURES                                                                 */
/* ************************************************************************** */

# define NAME			"so_long"
# define FLOOR			"textures/floor.xpm"
# define WALL			"textures/wall.xpm"
# define COIN			"textures/xbox.xpm"
# define PLAYER			"textures/player.xpm"
# define DOORC			"textures/close_door.xpm"
# define DOORO			"textures/open_door.xpm"

/* ************************************************************************** */
/*   STRUCTS                                                                  */
/* ************************************************************************** */

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_image
{
	void	*player;
	void	*collectable;
	void	*wall;
	void	*floor;
	void	*door_open;
	void	*door_close;
}	t_image;

typedef struct s_game
{
	int			fd;
	char		**map;
	char		**map_copy;
	int			map_height;
	int			map_width;
	int			c_player;
	int			c_collect;
	int			c_exit;
	int			c_moves;
	int			reach_collect;
	int			reach_exit;
	bool		start;
	bool		open_door;
	bool		access_exit;
	bool		found_exit;
	t_position	player_pos;
	t_position	exit_pos;
	t_position	*collect_pos;
	void		*mlx;
	void		*win;
	t_image		img;
}	t_game;

/* ************************************************************************** */
/*   PROTOTYPES                                                               */
/* ************************************************************************** */

//validation.c
int		validations(t_game *game);

//positions.c
int		set_player_pos(t_game *game, int x, int y);
int		set_exit_pos(t_game *game, int x, int y);

//utils.c
int		ft_open(char *map, t_game *game);
int		new_pos_x(int key, t_game *game, int new_y, int new_x);
int		new_pos_y(int key, t_game *game, int new_y, int new_x);
int		is_open(t_game *game, char next_tile);

//game_start.c
void	game_init(t_game *game);
int		ft_load_map(char *map, t_game *game);

//frees.c
int		close_window(t_game *game);
void	ft_free(t_game *game, char *line, int flag);
void	ft_free_arr(char **arr);
void	ft_free_collect_pos(t_game *game);

//load_images.c
int		ft_load_images(t_game *game);
void	ft_init_window(t_game *game);
void	ft_draw_map(t_game *game, int x, int y);
int		handle_key(int key, t_game *game);

//handle_key_helper.c
void	collect_check(t_game *game);
void	redraw_map(t_game *game, int new_x, int new_y, char next_tile);

//flood_fill.c
bool	flood_fill_caller(t_game *game);

#endif
