/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatesnorm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsai <atsai@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:51:20 by atsai             #+#    #+#             */
/*   Updated: 2018/01/16 16:19:47 by atsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h> // REMOVE THIS

/*
** THIS VERSION IS TO TAKE NEWTEST AND MAKE IT WORK WITH NORM
*/

#define I 0
#define L 1
#define PS 2
#define C 3
#define LS 4

/*
** I = index
** L = lines
** PS = poundsigns
** C = connections
** LS = linesize
*/

int		linesizefinder(char *input)
{
	int characters;

	characters = 0;
	while (input[characters] != '\n')
		characters++;
	return (characters);
}

void	reset(int *ps, int *lines, int *c)
{
	*ps = 0;
	*lines = 0;
	*c = 0;
}

/*
** changed *fileinput to *f because norm wants it that way.
*/


int		validates(char *f)
{
	int v[5];

	v[I] = -1;
	reset(&v[L], &v[PS], &v[C]);
    v[LS] = linesizefinder(f);
    if (v[LS] != 4)
		printf("It didn't sense a linesize of 4\n"); // REMOVE THIS
        return (0);
    while (f[++v[I]])
    {
        if (f[v[I]] != '.' && f[v[I]] != '#' && f[v[I]] != '\n')
			printf("It sensed things that weren't dots or poundsigns.\n"); // REMOVE THIS
            return (0);
        if (f[v[I]] == '\n' && (v[L] = (f[v[I] - 1] == '\n') ? v[L] : v[L] + 1))
            if (f[v[I] + 1] == '\n' && f[v[I] + 2] == '\n')
				printf("It sensed the wrong number of connections.\n"); // REMOVE THIS
                return (0);
        if (f[v[I]] == '#' && ++v[PS])
        {
            v[C] = cf1(f, v[I], v[L], v[LS]) + v[C] + cf2(f, v[I], v[L], v[LS]) + cf3(f, v[I], v[L], v[LS]);
        }
        if (v[L] == v[LS])
        {
            if (((f[v[I] + 1] != '\n') && (f[v[I] + 1] != '\0')) ||
		(v[PS] != 4) || (v[C] != 6 && v[C] != 8))
				printf("It sensed the wrong number of poundsigns.\n"); // REMOVE THIS
                return (0);
            reset(&v[PS], &v[L], &v[C]);
       }
    }
    return (1);
}
