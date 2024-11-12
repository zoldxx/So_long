/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inondation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:20:19 by dberreby          #+#    #+#             */
/*   Updated: 2023/03/15 14:44:12 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	inondation_droite(char **test, int i, int k)
{
	int	p;
	int	changement;

	p = 1;
	changement = 1;
	while (changement && test[i][k + p])
	{
		changement = 0;
		if (test[i][k + p] == '0' || test[i][k + p] == 'C')
		{
			test[i][k + p] = 'G';
			changement++;
		}
		p++;
	}
}

void	inondation_gauche(char **test, int i, int k)
{
	int	p;
	int	changement;

	p = 1;
	changement = 1;
	while (changement && p < k)
	{
		changement = 0;
		if (test[i][k - p] == '0' || test[i][k - p] == 'C')
		{
			test[i][k - p] = 'G';
			changement++;
		}
		p++;
	}
}

void	inondation_bas(char **test, int i, int k)
{
	int	p;
	int	changement;

	p = 1;
	changement = 1;
	while (changement && test[i + p][k])
	{
		changement = 0;
		if (test[i + p][k] == '0' || test[i + p][k] == 'C')
		{
			test[i + p][k] = 'G';
			changement++;
		}
		p++;
	}
}

void	inondation_haut(char **test, int i, int k)
{
	int	p;
	int	changement;

	p = 1;
	changement = 1;
	while (changement && p < i)
	{
		changement = 0;
		if (test[i - p][k] == '0' || test[i - p][k] == 'C')
		{
			test[i - p][k] = 'G';
			changement++;
		}
		p++;
	}
}

void	inondation(char **test, int i, int k)
{
	inondation_droite(test, i, k);
	inondation_gauche(test, i, k);
	inondation_haut(test, i, k);
	inondation_bas(test, i, k);
}
