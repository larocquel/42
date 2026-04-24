/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:31:22 by leoaguia          #+#    #+#             */
/*   Updated: 2025/08/04 18:43:34 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	valid_format(char *map)
{
	int	form_len;

	form_len = ft_strlen(map);
	if (form_len >= 4)
		form_len -= 4;
	if (ft_strncmp(map + form_len, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	ft_open(char *map, t_game *game)
{
	game->fd = open(map, O_RDONLY);
	if (game->fd == -1)
		return (close(game->fd), ft_putstr_fd(NO_FILE, 2),
			ft_putstr_fd(map, 2), ft_putstr_fd("\n", 2), 0);
	if (!valid_format(map))
	{
		close(game->fd);
		ft_putstr_fd(FORMAT_ERROR, 2);
		exit(1);
	}
	return (game->fd);
}

int	new_pos_x(int key, t_game *game, int new_y, int new_x)
{
	if ((key == XK_Left || key == XK_a) && game->map[new_y][new_x - 1] != '1')
		new_x--;
	else if ((key == XK_Right || key == XK_d)
		&& game->map[new_y][new_x + 1] != '1')
		new_x++;
	return (new_x);
}

int	new_pos_y(int key, t_game *game, int new_y, int new_x)
{
	if ((key == XK_Up || key == XK_w) && game->map[new_y - 1][new_x] != '1')
		new_y--;
	else if ((key == XK_Down || key == XK_s)
		&& game->map[new_y + 1][new_x] != '1')
		new_y++;
	return (new_y);
}

int	is_open(t_game *game, char next_tile)
{
	if (next_tile == 'E' || next_tile == 'O')
	{
		if (game->c_collect == 0)
		{
			ft_printf("🎉You won in %d moves!🎉\n", game->c_moves);
			ft_free(game, NULL, 1);
			exit(0);
		}
		return (ft_printf("Exit is locked! Collect all XBOXes first!\n"), 0);
	}
	return (1);
}
