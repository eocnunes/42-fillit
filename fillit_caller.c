/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_caller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 22:28:17 by enunes            #+#    #+#             */
/*   Updated: 2017/07/10 18:01:02 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fillit.h>

int		check_tetriminos(char *file)
{
	if (!check_chars(file))
		return (0);
	if (!check_width(file))
		return (0);
	if (!check_length(file))
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

char	**setup_puzzle(char *file)
{
	int		n;
	char	**puzzle;

	n = count_pieces(file);
	if (n > 26)
	{
		ft_putstr("error\n");
		return (0);
	}
	puzzle = (char **)malloc(sizeof(char *) * n);
	if (!puzzle)
		return (0);
	if (!get_pieces(file, puzzle))
		return (0);
	valid_pattern(puzzle, n);
	setup_letters(puzzle, n);
	int i = 0;
	while(i < n)
	{
		printf ("%i: %s\n", i, puzzle[i]);
		i++;
	}
	return (puzzle);
}


