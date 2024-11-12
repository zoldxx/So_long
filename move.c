/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:19:58 by dberreby          #+#    #+#             */
/*   Updated: 2023/03/16 17:15:44 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_game *game, int x, int y)
{
	if (game->map[game->x_perso][game->y_perso + 1] == '0'
		|| game->map[game->x_perso][game->y_perso + 1] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->grass, y, x);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->perso, y + 64,
			x);
		y += 64;
		game->move++;
		if (game->map[game->x_perso][game->y_perso + 1] == 'C')
			game->pocket++;
		game->map[game->x_perso][game->y_perso] = '0';
		game->map[game->x_perso][game->y_perso + 1] = 'P';
	}
	else if (game->map[game->x_perso][game->y_perso + 1] == 'E')
	{
		if (game->pocket == game->full_coin)
			ft_exit(game);
	}
	position_perso(&game);
}

void	move_left(t_game *game, int x, int y)
{
	if (game->map[game->x_perso][game->y_perso - 1] == '0'
		|| game->map[game->x_perso][game->y_perso - 1] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->grass, y, x);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->perso, y - 64,
			x);
		y -= 64;
		game->move++;
		if (game->map[game->x_perso][game->y_perso - 1] == 'C')
			game->pocket++;
		game->map[game->x_perso][game->y_perso] = '0';
		game->map[game->x_perso][game->y_perso - 1] = 'P';
	}
	else if (game->map[game->x_perso][game->y_perso - 1] == 'E')
	{
		if (game->pocket == game->full_coin)
			ft_exit(game);
	}
	position_perso(&game);
}

void	move_down(t_game *game, int x, int y)
{
	if (game->map[game->x_perso + 1][game->y_perso] == '0'
		|| game->map[game->x_perso + 1][game->y_perso] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->grass, y, x);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->perso, y, x
			+ 64);
		x += 64;
		game->move++;
		if (game->map[game->x_perso + 1][game->y_perso] == 'C')
			game->pocket++;
		game->map[game->x_perso][game->y_perso] = '0';
		game->map[game->x_perso + 1][game->y_perso] = 'P';
	}
	else if (game->map[game->x_perso + 1][game->y_perso] == 'E')
	{
		if (game->pocket == game->full_coin)
			ft_exit(game);
	}
	position_perso(&game);
}

void	move_up(t_game *game, int x, int y)
{
	if (game->map[game->x_perso - 1][game->y_perso] == '0'
		|| game->map[game->x_perso - 1][game->y_perso] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->grass, y, x);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->perso, y, x
			- 64);
		x -= 64;
		game->move++;
		if (game->map[game->x_perso - 1][game->y_perso] == 'C')
			game->pocket++;
		game->map[game->x_perso][game->y_perso] = '0';
		game->map[game->x_perso - 1][game->y_perso] = 'P';
	}
	else if (game->map[game->x_perso - 1][game->y_perso] == 'E')
	{
		if (game->pocket == game->full_coin)
			ft_exit(game);
	}
	position_perso(&game);
}

int	ft_input(int key, void *param)
{
	t_game			*game;
	static int		x;
	static int		y;
	unsigned int	tmp_move;

	game = (t_game *)param;
	x = game->x_perso * 64;
	y = game->y_perso * 64;
	tmp_move = game->move;
	if (key == 100 && game->map[game->x_perso][game->y_perso + 1] != '1')
		move_right(game, x, y);
	else if (key == 97 && game->map[game->x_perso][game->y_perso - 1] != '1')
		move_left(game, x, y);
	else if (key == 115 && game->map[game->x_perso + 1][game->y_perso] != '1')
		move_down(game, x, y);
	else if (key == 119 && game->map[game->x_perso - 1][game->y_perso] != '1')
		move_up(game, x, y);
	else if (key == 65307 || key == 1)
		ft_exit(game);
	if (tmp_move != game->move)
		return (ft_printf("\rnombre de mouvements : %u", tmp_move + 1));
	else
		return (1);
}
