/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:54:44 by dberreby          #+#    #+#             */
/*   Updated: 2023/03/14 15:46:35 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->grass)
		mlx_destroy_image(game->mlx, game->grass);
	if (game->perso)
		mlx_destroy_image(game->mlx, game->perso);
	if (game->coin)
		mlx_destroy_image(game->mlx, game->coin);
	if (game->door)
		mlx_destroy_image(game->mlx, game->door);
	if (game->fond)
		mlx_destroy_image(game->mlx, game->fond);
	if (game->bad)
		mlx_destroy_image(game->mlx, game->bad);
	ft_exit_end(game);
}

void	ft_exit_end(t_game *game)
{
	int	i;

	i = 0;
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
	}
	free(game->map);
	exit(0);
}

void	memset_game(t_game *game)
{
	game->mlx = NULL;
	game->wall = NULL;
	game->grass = NULL;
	game->perso = NULL;
	game->coin = NULL;
	game->door = NULL;
	game->fond = NULL;
	game->bad = NULL;
	game->map = NULL;
	game->mlx_win = NULL;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		if (!parsing_map(av[1]))
		{
			ft_printf("Error\nMap invalide\n");
			return (0);
		}
		init_game(&game, av[1]);
		game.mlx_win = mlx_new_window(game.mlx, 64 * game.nb_colonnes, 64
				* (game.nb_lignes + 1), "So_long");
		if (!game.mlx_win)
			ft_exit(&game);
		lire_map(&game);
		mlx_key_hook(game.mlx_win, ft_input, &game);
		mlx_hook(game.mlx_win, 17, 0, mlx_loop_end, game.mlx);
		mlx_loop(game.mlx);
		ft_exit(&game);
	}
	return (0);
}

// int	main(int ac, char **av)
// {
// 	t_game	game;

// 	if (ac == 2)
// 	{
// 		if (!parsing_map(av[1]))
// 		{
// 			ft_printf("Error\nMap invalide\n");
// 			return (0);
// 		}
// 		game.mlx = mlx_init();
// 		if (!game.mlx)
// 			ft_exit(&game);
// 		init_game(&game, av[1]);
// 		game.mlx_win = mlx_new_window(game.mlx, 64 * game.nb_colonnes, 64
// 				* (game.nb_lignes + 1), "So_long");
// 		if (!game.mlx_win)
// 			ft_exit(&game);
// 		lire_map(&game);
// 		mlx_key_hook(game.mlx_win, ft_input, &game);
// 		mlx_hook(game.mlx_win, 17, 0, mlx_loop_end, game.mlx);
// 		mlx_loop(game.mlx);
// 		ft_exit(&game);
// 	}
// 	return (0);
// }
