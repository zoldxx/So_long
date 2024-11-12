/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:09:40 by dberreby          #+#    #+#             */
/*   Updated: 2023/03/14 11:16:25 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	count_line(char *av)
{
	unsigned int	i;
	int				fd;
	char			tmp[1];

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, tmp, 1) != 0)
	{
		if (tmp[0] == '\n')
			i++;
	}
	close(fd);
	return (i + 2);
}

char	**get_map(char *av)
{
	char	*line;
	char	**map;
	int		fd;
	int		i;

	i = 0;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd, 0);
	if (!line)
		return (NULL);
	map = ft_calloc(count_line(av), sizeof(char *));
	if (!map)
		return (NULL);
	while (line)
	{
		map[i] = line;
		line = get_next_line(fd, 0);
		i++;
	}
	map[i] = NULL;
	get_next_line(fd, 1);
	free(line);
	close(fd);
	return (map);
}

void	put_something(t_game *game, int x, int y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, x, y);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->grass, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->perso, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->coin, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->door, x, y);
	else if (c == 'B')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->bad, x, y);
}

void	lire_map(t_game *game)
{
	int	i;
	int	k;
	int	x;
	int	y;

	i = 0;
	k = 0;
	x = 0;
	y = 0;
	while (game->map[i])
	{
		while (game->map[i][k] != '\n' && game->map[i][k] != '\0')
		{
			put_something(game, x, y, game->map[i][k]);
			x += 64;
			k++;
		}
		x = 0;
		y += 64;
		i++;
		k = 0;
	}
}
