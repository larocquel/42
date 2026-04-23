/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:07:28 by leoaguia          #+#    #+#             */
/*   Updated: 2025/06/30 22:40:18 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_init(t_game *game)
{
	game->fd = 0;
	game->map = NULL;
	game->map_height = 0;
	game->map_width = 0;
	game->c_player = 0;
	game->c_exit = 0;
	game->c_collect = 0;
	game->access_exit = false;
	game->start = false;
	game->open_door = false;
	game->c_moves = 0;
	game->player_pos.x = 0;
	game->player_pos.y = 0;
	game->exit_pos.x = 0;
	game->exit_pos.y = 0;
	game->collect_pos = NULL;
}

static char	*ft_remove_nl(char *line)
{
	char	*temp;

	temp = line;
	line = ft_strtrim(line, "\n");
	free(temp);
	return (line);
}

static int	ft_get_height(t_game *game)
{
	int	y;

	y = 0;
	while (game->map[y])
		y++;
	return (y);
}

static int	ft_add_line(t_game *game, char *line, int i, int j)
{
	char	**temp;

	if (!line)
		return (0);
	temp = malloc(sizeof(char *) * (game->map_height + 2));
	if (!temp)
		return (0);
	while (i < game->map_height)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!temp[i])
		return (ft_free_arr(temp), 0);
	while (j <= (int)ft_strlen(line))
	{
		temp[i][j] = line[j];
		j++;
	}
	temp[++game->map_height] = NULL;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	ft_load_map(char *map, t_game *game)
{
	int		checker;
	char	*line;

	checker = ft_open(map, game);
	if (!checker)
		return (0);
	line = NULL;
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
			break ;
		line = ft_remove_nl(line);
		if (!ft_add_line(game, line, 0, 0))
			return (ft_free(game, line, 0), 0);
		free(line);
	}
	if (game->map)
		game->map_height = ft_get_height(game);
	else
		return (ft_free(game, NULL, 0), 0);
	return (get_next_line(-1), 1);
}
