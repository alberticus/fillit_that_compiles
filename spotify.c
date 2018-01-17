/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spotify.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsai <atsai@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:33:40 by atsai             #+#    #+#             */
/*   Updated: 2018/01/16 15:38:08 by atsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	spotify(char **grid, int dimension)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < dimension)
	{
		if (x == dimension)
		{
			x = 0;
			y++;
		}
		grid[x][y] = '.';
		x++;
	}
}

void	undo(char **grid, char character, int dimension)
{
	int x;
	int y;
	char firstflag;

	x = 0;
	y = 0;
	firstflag = 0;
	while (y < dimension)
	{
		if (grid[x][y] == character)
		{
			if (firstflag == 0)
			{
				grid[x][y] = '*';
				firstflag = 1;
			}
			else
				grid[x][y] = '.';
		}
		if (x == dimension)
		{
			x = 0;
			y++;
		}
		x++;
	}
}
/*
void	findstar(int x, int y, char** grid, int dimension)
{
	while (y < dimension)
	{
		if (grid[x][y] == '*')
			grid[x][y] = '.';
		if (x == dimension)
		{
			x = -1;
			y++;
		}
		x++;
	}
}
*/
