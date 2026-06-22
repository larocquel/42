/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:48:55 by leoaguia          #+#    #+#             */
/*   Updated: 2025/06/30 22:49:50 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	set_player_pos(t_game *game, int x, int y)
{
	game->c_player++;
	if (game->c_player > 1)
	{
		game->c_player = 0;
		return (0);
	}
	game->player_pos.x = x;
	game->player_pos.y = y;
	return (1);
}

int	set_exit_pos(t_game *game, int x, int y)
{
	game->c_exit++;
	if (game->c_exit > 1)
	{
		game->c_exit = 0;
		return (0);
	}
	game->exit_pos.x = x;
	game->exit_pos.y = y;
	return (1);
}
