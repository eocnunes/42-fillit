/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_puzzle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguirre <gio_aguirre19@yahoo.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 20:43:18 by gaguirre          #+#    #+#             */
/*   Updated: 2017/07/08 01:45:51 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fillit.h>

int		count_pieces(char *file)
{
	int i;
	int piece;

	i = 0;
	piece = 0;
	while (file[i])
	{
		if (file[i] == '\n')
		{
			if (file[i + 1] == '\n' || file[i + 1] == '\0')
				piece++;
		}
		i++;
	}
	return (piece);
}

int		create_piece(char *grid, char *file)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (j <= 16)
	{
		if (file[i] == '.' || file[i] == '#')
		{
			grid[j] = file[i];
			j++;
		}
		if (file[i] == '\n')
		{
			if (file[i + 1] == '\n' || file[i + 1] == '\0')
			{
				grid[j] = '\0';
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int		get_pieces(char *file, char **puzzle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (file[i])
	{
		puzzle[j] = (char *)malloc(sizeof(char) * 16 + 1);
		if (!(puzzle[j]))
			return (0);
		create_piece(puzzle[j], &file[i]);
		i = i + 21;
		ft_putstr(puzzle[j]);
		ft_putchar('\n');
		j++;
	}
	puzzle[j] = (char *)malloc(sizeof(char));
	puzzle[j][0] = '\0';
	ft_putstr(puzzle[j]);
	ft_putchar('\n');
	return (1);
}
