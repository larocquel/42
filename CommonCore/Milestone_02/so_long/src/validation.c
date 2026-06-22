/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:53:57 by leoaguia          #+#    #+#             */
/*   Updated: 2025/07/07 17:36:54 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	valid_lines(t_game *game)
{
	int	y;
	int	x;
	int	prev_len;
	int	len;

	y = 0;
	prev_len = -1;
	while (game->map[y])
	{
		x = 0;
		len = 0;
		while (game->map[y][x])
		{
			x++;
			len++;
		}
		if (prev_len != -1 && len != prev_len)
			return (0);
		prev_len = len;
		y++;
	}
	game->map_width = prev_len;
	game->map_height = y;
	return (1);
}

static int	valid_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[0][x] && x < game->map_width)
	{
		if (game->map[0][x] != '1' || game->map[game->map_height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 1;
	while (y < game->map_height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->map_width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	valid_chars(t_game *game, int x, int y)
{
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				game->c_collect++;
			else if (game->map[y][x] == 'P')
			{
				if (!set_player_pos(game, x, y))
					return (0);
			}
			else if (game->map[y][x] == 'E')
			{
				if (!set_exit_pos(game, x, y))
					return (0);
			}
			else if (game->map[y][x] != '1' && game->map[y][x] != '0')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static void	set_collectables_pos(t_game *game)
{
	int	i;
	int	x;
	int	y;

	game->collect_pos = malloc(sizeof(t_position) * game->c_collect);
	y = 0;
	i = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
			{
				game->collect_pos[i].x = x;
				game->collect_pos[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

int	validations(t_game *game)
{
	if (!game->map || !game->map[0])
		return (ft_free(game, NULL, 0), ft_putstr_fd(EMPTY, 2), 0);
	if (!valid_lines(game))
		return (ft_free(game, NULL, 0), ft_putstr_fd(MAP_SIZE, 2), 0);
	else if (!valid_walls(game))
		return (ft_free(game, NULL, 0), ft_putstr_fd(MAP_WALLS, 2), 0);
	else if (!valid_chars(game, 0, 0))
	{
		if (game->c_player == 0 || game->c_exit == 0)
			return (ft_free(game, NULL, 0), ft_putstr_fd(INV_C, 2),
				ft_putstr_fd(INV_C2, 2), 0);
		return (ft_free(game, NULL, 0), ft_putstr_fd(INVALID_CHAR, 2), 0);
	}
	if (game->c_collect == 0)
		return (ft_free(game, NULL, 0), ft_putstr_fd(INV_C, 2),
			ft_putstr_fd(INV_C2, 2), 0);
	set_collectables_pos(game);
	return (1);
}
