/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SplitIntoSections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsai <atsai@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:19:24 by atsai             #+#    #+#             */
/*   Updated: 2017/12/28 15:32:43 by atsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** replaces the \n inbetween the tetriminos into a ' ' (space character)
*/

char		*delimit_tetro(char *clone)
{
	int index;

	index = 0;
	while (clone[index])
	{
		if (clone[index] == '\n' && clone[index - 1] == '\n')
			clone[index] = ' ';
		index++;
	}
	return (clone);
}

/*
** copies the original string with all the tetriminos,
** split the copy on the ' ' (space character)
** that replaces the \n inbetween the tetriminos,
** **tetriminos is a double-array thatstores all the pieces in
** their orgininal form
*/

char		**split_into_tetro(char *input)
{
	char *clone_input;
	char **tetriminos;

	clone_input = (char*)malloc(sizeof(ft_strlen(input)) + 1);
	ft_strcpy(clone_input, input);
	delimit_tetro(clone_input);
	tetriminos = ft_strsplit(clone_input, ' ');
	return (tetriminos);
}
