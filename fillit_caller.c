/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_caller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 22:28:17 by enunes            #+#    #+#             */
/*   Updated: 2017/07/20 20:16:58 by gaguirre         ###   ########.fr       */
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

int		setup_puzzle(char *file)
{
	int		num;
	char	**puzzle;

	num = count_pieces(file);
	if (num > 26)
	{
		ft_putstr("error\n");
		return (0);
	}
	puzzle = (char **)ft_memalloc(sizeof(char *) * (num + 1));
	if (!puzzle)
		return (0);
	if (!get_pieces(file, puzzle))
		return (0);
	valid_pattern(puzzle, num);
	setup_letters(puzzle, num);
	solve(puzzle, num);
	return (1);
}


