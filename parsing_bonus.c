/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:14:06 by dberreby          #+#    #+#             */
/*   Updated: 2023/03/13 14:38:26 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(char **map)
{
	int	i;
	int	k;
	int	size;

	i = 0;
	k = 0;
	while (map[i][k] != '\0' && map[i][k] != '\n')
		k++;
	size = k;
	k = 0;
	i++;
	while (map[i])
	{
		while (map[i][k] != '\0' && map[i][k] != '\n')
			k++;
		if (k != size)
			return (0);
		k = 0;
		i++;
	}
	return (1);
}

int	is_walled_up(char **map)
{
	int	k;

	k = 0;
	while (map[0][k] != '\0' && map[0][k] != '\n')
	{
		if (map[0][k] != '1')
			return (0);
		k++;
	}
	return (1);
}

int	is_walled(char **map)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	if (!is_walled_up(map))
		return (0);
	while (map[i + 1])
	{
		if (map[i][k] != '1')
			return (0);
		while (map[i][k + 1] != '\0' && map[i][k + 1] != '\n')
			k++;
		if (map[i][k] != '1')
			return (0);
		i++;
		k = 0;
	}
	while (map[i][k] != '\0')
	{
		if (map[i][k] != '1')
			return (0);
		k++;
	}
	return (1);
}

int	valid_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (i < 4)
		return (0);
	if (str[i] != 'r')
		return (0);
	i--;
	if (str[i] != 'e')
		return (0);
	i--;
	if (str[i] != 'b')
		return (0);
	i--;
	if (str[i] != '.')
		return (0);
	return (1);
}

int	parsing_map(char *av)
{
	char	**map;
	int		i;
	int		res;

	i = 0;
	res = 1;
	map = get_map(av);
	if (!map)
		return (0);
	if (!valid_name(av) || !is_rectangle(map) || !is_walled(map)
		|| !count_pe(map) || !count_c_and_valid_char(map))
		res = 0;
	if (res == 1)
	{
		if (!is_doable(map))
			res = 0;
	}
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (res);
}
