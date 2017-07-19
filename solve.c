/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 23:22:32 by enunes            #+#    #+#             */
/*   Updated: 2017/07/17 22:18:36 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	place_tetri(char **grid, char *tetri, int row, int col)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (tetri[i])
	{
		if(tetri[i] != '.')
			grid[row][col] = tetri[i];
		i++;
		col++;
		n++;
		if (n == 4)
		{
			row++;
			col = col - 4;
			n = 0;
		}
	}
}

void	remove_tetri(char **grid, char *tetri)
{
	int		i;
	int		row;
	int 	col;
	char	tmp;

	i = 0;
	row = 0;
	while (*tetri == '.')
		i++;
	tmp = *tetri;
	while (grid[row])
	{
		col = 0;
		while(grid[row][col])
		{
			if (grid[row][col] == tmp)
				grid[row][col] = '.';
			col++;
		}
		row++;
	}
}

int		check_place(char **grid, char *tetri, int row, int col)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (tetri[i])
	{
		if (n == 4)
		{
			row++;
			n = 0;
			col = col - 4;
		}
		if (tetri[i] >= 'A' && tetri[i] <= 'Z' && grid[row][col] != '.')
			return (0);
		n++;
		col++;
		i++;
	}
	return (1);
}

int		recursion(char **grid, char **puzzle, int row, int col)
{
	if (!*puzzle)
		return (0);
	while (grid[row])
	{
		while (grid[row][col])
		{
			if (check_place(grid, *puzzle, row, col))
			{
				place_tetri(grid, *puzzle, row, col);
				if (recursion(grid, (1 + puzzle), 0, 0))
					remove_tetri(grid, *puzzle);
				else
					return (0);
			}
			col++;
		}
		row++;
		col = 0;
	}
	return (1);
}
