/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:33:09 by leoaguia          #+#    #+#             */
/*   Updated: 2025/07/07 17:38:41 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		game_init(&game);
		ft_load_map(av[1], &game);
		if (!validations(&game))
			return (1);
		if (!flood_fill_caller(&game))
			return (ft_free(&game, NULL, 0), 1);
		game.mlx = mlx_init();
		if (!ft_load_images(&game))
			return (ft_free(&game, NULL, 0), free(game.collect_pos), 1);
		ft_init_window(&game);
		ft_draw_map(&game, 0, 0);
		mlx_key_hook(game.win, handle_key, &game);
		mlx_loop(game.mlx);
		return (0);
	}
	return (ft_printf(AV_ERROR), 1);
}
