/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:41:04 by leoaguia          #+#    #+#             */
/*   Updated: 2025/06/30 22:43:01 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	collect_check(t_game *game)
{
	if (game->c_collect == 0)
	{
		game->map[game->exit_pos.y][game->exit_pos.x] = 'O';
		mlx_put_image_to_window(game->mlx, game->win, game->img.door_open,
			game->exit_pos.x * 32, game->exit_pos.y * 32);
	}
	return ;
}

void	redraw_map(t_game *game, int new_x, int new_y, char next_tile)
{
	if (next_tile != '1' && next_tile != 'E')
	{
		game->map[game->player_pos.y][game->player_pos.x] = '0';
		if (new_x != game->player_pos.x || new_y != game->player_pos.y)
		{
			game->player_pos.x = new_x;
			game->player_pos.y = new_y;
			game->map[new_y][new_x] = 'P';
			ft_printf("Moves: %d\n", ++game->c_moves);
			ft_draw_map(game, 0, 0);
		}
	}
}
