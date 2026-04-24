/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:23:07 by leoaguia          #+#    #+#             */
/*   Updated: 2025/06/30 22:45:40 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_load_images(t_game *game)
{
	int	x;
	int	y;

	x = 32;
	y = 32;
	game->img.player = mlx_xpm_file_to_image(game->mlx, PLAYER, &x, &y);
	game->img.collectable = mlx_xpm_file_to_image(game->mlx, COIN, &x, &y);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL, &x, &y);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &x, &y);
	game->img.door_open = mlx_xpm_file_to_image(game->mlx, DOORO, &x, &y);
	game->img.door_close = mlx_xpm_file_to_image(game->mlx, DOORC, &x, &y);
	if (!game->img.player || !game->img.collectable || !game->img.wall
		|| !game->img.floor || !game->img.door_open
		|| !game->img.door_close)
		return (0);
	return (1);
}

void	ft_init_window(t_game *game)
{
	int	x;
	int	y;

	game->start = true;
	x = game->map_width * 32;
	y = game->map_height * 32;
	game->win = mlx_new_window(game->mlx, x, y, NAME);
	mlx_hook(game->win, 17, 0L, close_window, game);
}

static void	draw_map_helper(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.wall, x * 32, y * 32);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.floor, x * 32, y * 32);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player, x * 32, y * 32);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.collectable, x * 32, y * 32);
	else if (game->map[y][x] == 'E')
	{
		if (game->open_door)
			mlx_put_image_to_window(game->mlx, game->win,
				game->img.door_open, x * 32, y * 32);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->img.door_close, x * 32, y * 32);
	}
}

void	ft_draw_map(t_game *game, int x, int y)
{
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			draw_map_helper(game, x, y);
			x++;
		}
		y++;
	}
}

int	handle_key(int key, t_game *game)
{
	char	next_tile;
	int		new_x;
	int		new_y;

	new_x = game->player_pos.x;
	new_y = game->player_pos.y;
	if (key == XK_Escape)
	{
		ft_printf("EXITING GAME!\n");
		ft_free(game, NULL, 1);
		exit(0);
	}
	new_y = new_pos_y(key, game, new_y, new_x);
	new_x = new_pos_x(key, game, new_y, new_x);
	next_tile = game->map[new_y][new_x];
	if (next_tile == 'C')
		ft_printf("Collectables left: %d\n", --game->c_collect);
	if (!is_open(game, next_tile))
		return (0);
	collect_check(game);
	redraw_map(game, new_x, new_y, next_tile);
	return (0);
}
