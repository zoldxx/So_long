/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:57:48 by dberreby          #+#    #+#             */
/*   Updated: 2023/03/14 16:35:38 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position_perso(t_game **game)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while ((*game)->map[i])
	{
		while ((*game)->map[i][k])
		{
			if ((*game)->map[i][k] == 'P')
			{
				(*game)->x_perso = i;
				(*game)->y_perso = k;
			}
			k++;
		}
		k = 0;
		i++;
	}
}

int	count_coin(t_game *game)
{
	char	**map;
	int		i;
	int		k;
	int		compteur;

	map = game->map;
	i = 0;
	k = 0;
	compteur = 0;
	while (map[i])
	{
		while (map[i][k])
		{
			if (map[i][k] == 'C')
				compteur++;
			k++;
		}
		k = 0;
		i++;
	}
	return (compteur);
}

int	nb_col(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
		i++;
	return (i - 1);
}

int	nb_line(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	return (i);
}

void	init_game(t_game *game, char *av)
{
	memset_game(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_exit(game);
	i_picture(game);
	game->map = get_map(av);
	if (!game->map)
		ft_exit(game);
	game->nb_colonnes = nb_col(game);
	game->nb_lignes = nb_line(game);
	position_perso(&game);
	game->pocket = 0;
	game->full_coin = count_coin(game);
	game->move = 0;
}

// void	init_game(t_game *game, char *av)
// {
// 	memset_game(game);
// 	i_picture(game);
// 	game->map = get_map(av);
// 	game->nb_colonnes = nb_col(game);
// 	game->nb_lignes = nb_line(game);
// 	position_perso(&game);
// 	game->pocket = 0;
// 	game->full_coin = count_coin(game);
// 	game->move = 0;
// }
