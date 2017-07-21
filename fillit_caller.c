/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_caller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 22:28:17 by enunes            #+#    #+#             */
/*   Updated: 2017/07/20 22:10:17 by gaguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fillit.h>

int		check_tetriminos(char *file)
{
	int		pieces;

	if (!check_width(file))
		return (0);
	if (!check_length(file))
		return (0);
	pieces = count_pieces(file);
	if (!check_chars(file, pieces))
		return (0);
	return (1);
}

void	setup_letters(char **puzzle, int num)
{
	int	i;
	int j;

	i = 0;
	while (i < num)
	{
		j = 0;
		while(puzzle[i][j])
		{
			if (puzzle[i][j] == '\0')
				break ;
			if(puzzle[i][j] == '#')
				puzzle[i][j] = (65 + i);
			j++;
		}
		i++;
	}
}
