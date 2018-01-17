/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveandplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsai <atsai@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:23:45 by atsai             #+#    #+#             */
/*   Updated: 2018/01/16 15:46:14 by atsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
void spotify(char **grid, int dimension)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < dimension)
	{
		grid[x][y] = '.';
		if (!grid[x][y])
		{
			y++;
			x = 0;
		}
	}
}
*/

void move_to_corner(char piece[][4])
{
	int x = 0;
	int y = 0;
	int zeroX = 0;
	int zeroY = 0;
	while (piece[x][y] != '#')
	{
		x++;
		if (!piece[x][y])
		{
			x = 0;
			y++;
		}
	}
	while (y < 4)
	{
		if (!piece[x][y])
		{
			x = 0;
			y++;
			zeroX = 0;
			zeroY++;
		}
		piece[zeroX][zeroY] = piece[x][y];
		x++;
		zeroX++;
	}
}

char **place_piece(char piece[][4], char **grid, int x, int y, char letter)
{
	int startX = 0;
	int startY = 0;
	int poundsigns = 0;

	while (piece[startX][startY] != '#')
	{
		while (piece[startX][startY])
			startX++;
		startX = 0;
		startY++;
	}
	while (piece[startX][startY] && poundsigns < 4)
	{
		if (piece[startX][startY] == '#')
			grid[x][y] = letter;
		startX++;
		startY++;
		x++;
		y++;
	}
return (grid);
}

int can_place(int grid_x, int grid_y, char **grid, char piece[][4])
{
	int gX = grid_x;
	int gY = grid_y;
	int checkX = 0;
	int checkY = 0;
	int poundsigns = 0;

	while (piece[checkX][checkY] != '#')
	{
		while (piece[checkX][checkY])
			checkX++;
		checkX = 0;
		checkY++;
	}
	while (gY < 4 && poundsigns < 4)
	{
		while (grid[gX][gY] && piece[checkX][checkY])
		{
			if (piece[checkX][checkY] == '#')
			{
				if (grid[gX][gY] != '.')
					return (0);
				poundsigns++;
			}
		gX++;
		checkX++;
		}
		if (!grid[gX][gY])
		{
			gX = 0;
			gY++;
		}
		if (!piece[checkX][checkY])
		{
			checkX = 0;
			checkY++;
		}
	}
    return (1);
}

int piececounter(char **array)
{
    int index;

    index = 0;
    while (array[index])
        index++;
    return (index);
}

void OneD_TwoD(char *input, char output[4][4])
{
    int x;
    int y;
    int index;

    x = 0;
    y = 0;
    index = 0;

    while (input[index] && output[x][y])
    {
        while (input[index] != '\n')
        {
        output[x][y] = input[index];
        index++;
        x++;
        }
        index++;
        y++;
        x = 0;
    }
}
