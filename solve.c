/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 23:22:32 by enunes            #+#    #+#             */
/*   Updated: 2017/07/14 15:04:42 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		row;
	int 	col;
	char	tmp;

	row = 0;
	while (*tetri = '.')
		i++;
	tmp = *tetri;
	while (grid[row])
	{
		col = 0;
		while(grid[row][col])
		{
			if (grid[row][col] == tmp)
				board[row][col] = '.';
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
