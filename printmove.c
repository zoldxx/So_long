/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:51:13 by dberreby          #+#    #+#             */
/*   Updated: 2023/03/20 14:53:56 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	size(long nb)
{
	int	r;

	r = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		r++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		r++;
	}
	return (r);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*r;
	int		i;

	nb = n;
	i = size(nb);
	r = malloc(sizeof(char) * (size(nb) + 1));
	if (r == 0)
		return (0);
	r[i] = '\0';
	i--;
	if (nb == 0)
		r[0] = '0';
	if (nb < 0)
	{
		r[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		r[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (r);
}

int	ft_printmove(t_game *game, int nb)
{
	char	*itoto;

	itoto = ft_itoa(nb);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->fond, 64,
		(game->nb_lignes) * 64);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->fond, 128,
		(game->nb_lignes) * 64);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->fond, 192,
		(game->nb_lignes) * 64);
	mlx_string_put(game->mlx, game->mlx_win, 10, ((game->nb_lignes * 64) + 32),
		100000, "moves : ");
	mlx_string_put(game->mlx, game->mlx_win, 64, ((game->nb_lignes * 64) + 32),
		100000, itoto);
	free(itoto);
	return (1);
}
