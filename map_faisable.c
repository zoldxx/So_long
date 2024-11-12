/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_faisable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:25:52 by dberreby          #+#    #+#             */
/*   Updated: 2023/03/15 14:44:01 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_first_char(char **map, char c, int *i, int *k)
{
	*i = 0;
	*k = 0;
	while (map[*i])
	{
		while (map[*i][*k])
		{
			if (map[*i][*k] == c)
				break ;
			(*k)++;
		}
		if (map[*i][*k] == c)
			break ;
		(*i)++;
		*k = 0;
	}
}

int	is_g(char **map)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (map[i])
	{
		while (map[i][k])
		{
			if (map[i][k] == 'G')
				return (1);
			k++;
		}
		k = 0;
		i++;
	}
	return (0);
}

int	map_ok(char **map)
{
	int	i;
	int	k;
	int	compteur_e;
	int	compteur_c;

	i = -1;
	k = 0;
	compteur_e = 0;
	compteur_c = 0;
	while (map[++i])
	{
		while (map[i][k])
		{
			if (map[i][k] == 'E')
				compteur_e++;
			else if (map[i][k] == 'C')
				compteur_c++;
			k++;
		}
		k = 0;
	}
	if (compteur_c == 0 && compteur_e == 0)
		return (1);
	else
		return (0);
}

void	check_e(char **map, int i, int k)
{
	if (map[i][k + 1] == 'A')
		map[i][k] = 'A';
	if (map[i][k - 1] == 'A')
		map[i][k] = 'A';
	if (map[i + 1][k] == 'A')
		map[i][k] = 'A';
	if (map[i - 1][k] == 'A')
		map[i][k] = 'A';
}

int	is_doable(char **test)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	find_first_char(test, 'P', &i, &k);
	test[i][k] = 'A';
	inondation(test, i, k);
	while (is_g(test))
	{
		find_first_char(test, 'G', &i, &k);
		test[i][k] = 'A';
		inondation(test, i, k);
	}
	find_first_char(test, 'E', &i, &k);
	check_e(test, i, k);
	if (!map_ok(test))
		return (0);
	else
		return (1);
}
