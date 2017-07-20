/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 23:22:32 by enunes            #+#    #+#             */
/*   Updated: 2017/07/19 21:13:09 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
//		printf("ival: %d\n", i);
	}
//	printf("oo\n");
}

char	get_letter(char *str)
{
	while (*str == '.')
		str++;
	return (*str);
}

void	remove_tetri(char **grid, char *tetri, int row, int col)
{
	char	ch;
	int		i;

	ch = get_letter(tetri);
	i = 0;
	while (grid[row])
	{
		col = 0;
		while (grid[row][col])
		{
			if (i == 4)
				return ;
			if (grid[row][col] == ch)
			{
				i++;
				grid[row][col] = '.';
			}
			col++;
		}
		row++;
	}
}

int		check_place(char **grid, char *tetri, int row, int col)
{
	int i;
	int n;
	int check;

	i = 0;
	n = 0;
	check = 0;
	while (tetri[i])
	{
		if (tetri[i] != '.'  && grid[row][col] == '.')
			check++;
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
	if (check == 4)
		return (1);
	else
		return (0);
}

int		recursion(char **grid, char **puzzle, int row, int col)
{
	if (!*puzzle)
		return (1);
	while (grid[row] != 0)
	{
		while (grid[row][col] != 0)
		{
			if (check_place(grid, *puzzle, row, col))
			{
				printf("check for %s ok\n", *puzzle);
				place_tetri(grid, *puzzle, row, col);
				print_grid(grid, 4);
				if (!recursion(grid, (puzzle + 1), 0, 0))
					return (1);
				else
					remove_tetri(grid, *puzzle, row, col);
			}
			col++;
		}
		row++;
		col = 0;
	}
	return (0);
}
