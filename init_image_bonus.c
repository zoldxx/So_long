/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:46:14 by dberreby          #+#    #+#             */
/*   Updated: 2023/03/14 15:47:39 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_wall(t_game *game)
{
	char	*wall;
	int		i;

	i = 1;
	wall = "./xpm/mur.xpm";
	game->wall = mlx_xpm_file_to_image(game->mlx, wall, &i, &i);
	if (!game->wall)
		return (0);
	return (1);
}

int	init_grass(t_game *game)
{
	char	*grass;
	int		i;

	grass = "./xpm/sol.xpm";
	i = 1;
	game->grass = mlx_xpm_file_to_image(game->mlx, grass, &i, &i);
	if (!game->grass)
		return (0);
	return (1);
}

int	init_perso(t_game *game)
{
	char	*perso;
	int		i;

	perso = "./xpm/ludwig.xpm";
	i = 1;
	game->perso = mlx_xpm_file_to_image(game->mlx, perso, &i, &i);
	if (!game->perso)
		return (0);
	return (1);
}

int	init_coin(t_game *game)
{
	char	*coin;
	int		i;

	coin = "./xpm/piece.xpm";
	i = 1;
	game->coin = mlx_xpm_file_to_image(game->mlx, coin, &i, &i);
	if (!game->coin)
		return (0);
	return (1);
}

void	i_picture(t_game *game)
{
	char		*door;
	char		*fond;
	char		*bad;
	int			i;

	door = "./xpm/peach.xpm";
	fond = "./xpm/carre-noir.xpm";
	bad = "./xpm/mario.xpm";
	i = 1;
	if (!init_perso(game) || !init_wall(game))
		ft_exit(game);
	if (!init_grass(game))
		ft_exit(game);
	if (!init_coin(game))
		ft_exit(game);
	game->door = mlx_xpm_file_to_image(game->mlx, door, &i, &i);
	if (!game->door)
		ft_exit(game);
	game->bad = mlx_xpm_file_to_image(game->mlx, bad, &i, &i);
	if (!game->bad)
		ft_exit(game);
	game->fond = mlx_xpm_file_to_image(game->mlx, fond, &i, &i);
	if (!game->fond)
		ft_exit(game);
}

// void	i_picture(t_game *game)
// {
// 	char		*door;
// 	char		*fond;
// 	char		*bad;
// 	int			i;

// 	door = "./xpm/peach.xpm";
// 	fond = "./xpm/carre-noir.xpm";
// 	bad = "./xpm/mario.xpm";
// 	i = 1;
// 	if (!init_perso(game))
// 		ft_exit(game);
// 	if (!init_wall(game))
// 		ft_exit(game);
// 	if (!init_grass(game))
// 		ft_exit(game);
// 	if (!init_coin(game))
// 		ft_exit(game);
// 	game->door = mlx_xpm_file_to_image(game->mlx, door, &i, &i);
// 	if (!game->door)
// 		ft_exit(game);
// 	game->bad = mlx_xpm_file_to_image(game->mlx, bad, &i, &i);
// 	if (!game->bad)
// 		ft_exit(game);
// 	game->fond = mlx_xpm_file_to_image(game->mlx, fond, &i, &i);
// 	if (!game->fond)
// 		ft_exit(game);
// }
