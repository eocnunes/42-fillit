/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_caller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 22:28:17 by enunes            #+#    #+#             */
/*   Updated: 2017/07/09 02:40:18 by enunes           ###   ########.fr       */
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

void	setup_letters(char **puzzle)
{
	int	i;
	int j;
	char *tmp;

	i = 0;
	tmp = *puzzle;
	while (tmp[i])
	{
		j = 0;
		if (puzzle[i][j] == '\0')
			return ;
		while(puzzle[i][j])
		{
			if(puzzle[i][j] == '#')
				puzzle[i][j] = (65 + i);
			j++;
		}
//		printf("i:%d\n", i);
		printf("%s\n", puzzle[i]);
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
	printf("First: %s\n", *puzzle);
	valid_pattern(puzzle, n);
	setup_letters(puzzle);
//	printf ("%s\n", *puzzle);
	return (puzzle);
}


