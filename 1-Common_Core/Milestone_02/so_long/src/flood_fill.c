/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:49:44 by leoaguia          #+#    #+#             */
/*   Updated: 2025/06/30 22:36:54 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	map_dup(t_game *game)
{
	int	y;

	y = 0;
	game->map_copy = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map_copy)
		return ;
	while (y < game->map_height)
	{
		game->map_copy[y] = ft_strdup(game->map[y]);
		if (!game->map_copy[y])
		{
			while (--y >= 0)
				free(game->map_copy[y]);
			free(game->map_copy);
			return ;
		}
		y++;
	}
	game->map_copy[y] = NULL;
}

static bool	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_height
		|| game->map_copy[y][x] == '1' || game->map_copy[y][x] == 'F')
		return (game->found_exit);
	if (game->map_copy[y][x] == 'C')
		game->reach_collect++;
	if (game->map_copy[y][x] == 'E')
	{
		game->reach_exit++;
		game->found_exit = true;
	}
	game->map_copy[y][x] = 'F';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
	return (game->found_exit);
}

bool	flood_fill_caller(t_game *game)
{
	int	i;

	map_dup(game);
	if (!game->map_copy)
		return (false);
	game->reach_collect = 0;
	game->reach_exit = 0;
	flood_fill(game, game->player_pos.x, game->player_pos.y);
	i = 0;
	while (i < game->map_height)
	{
		free(game->map_copy[i]);
		i++;
	}
	free(game->map_copy);
	game->map_copy = NULL;
	if (game->reach_collect == game->c_collect && game->reach_exit > 0)
		return (true);
	ft_printf("Error: Can't reach collectables or exit!\n");
	return (false);
}
