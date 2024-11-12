/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:29:56 by dberreby          #+#    #+#             */
/*   Updated: 2023/03/13 14:35:50 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_c_and_valid_char(char **map)
{
	int	i;
	int	k;
	int	compteur_collectibles;

	i = 0;
	k = 0;
	compteur_collectibles = 0;
	while (map[i])
	{
		while (map[i][k] != '\n' && map[i][k] != '\0')
		{
			if (map[i][k] == 'C')
				compteur_collectibles++;
			else if (map[i][k] != 'E' && map[i][k] != 'P' && map[i][k] != '0'
					&& map[i][k] != '1' && map[i][k] != 'C')
				return (0);
			k++;
		}
		i++;
		k = 0;
	}
	if (compteur_collectibles > 0)
		return (1);
	else
		return (0);
}

int	count_pe(char **map)
{
	int	i;
	int	k;
	int	compteur_entree;
	int	compteur_sortie;

	i = -1;
	k = 0;
	compteur_entree = 0;
	compteur_sortie = 0;
	while (map[++i])
	{
		while (map[i][k] != '\0' && map[i][k] != '\n')
		{
			if (map[i][k] == 'E')
				compteur_sortie++;
			else if (map[i][k] == 'P')
				compteur_entree++;
			k++;
		}
		k = 0;
	}
	if (compteur_entree == 1 && compteur_sortie == 1)
		return (1);
	else
		return (0);
}
