/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguirre <gio_aguirre19@yahoo.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:18:26 by gaguirre          #+#    #+#             */
/*   Updated: 2017/07/15 21:32:45 by gaguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fillit.h>

char		**create_grid(int size)
{
	int		i;
	int		j;
	char	**grid;
	int		size_c;

	size_c = size + 3;
	grid = (char **)malloc(sizeof(*grid) * size_c);
	if (!grid)
		return (0);
	i = -1;
	while (++i < size)
	{
		grid[i] = ft_strnew(size_c);
		if (!grid)
			return (0);
		j = -1;
		while (++j < size)
			grid[i][j] = '.';
	}
	while (i <= size_c)
	{
		grid[i] = ft_strnew(size_c);
		i++;
	}
	return (grid);
}

int		init_size(int tetri)
{
	int i;
	int min;

	i = 2;
	min = tetri * 4;
	while (min > (i * i))
		i++;
	return (i);
}
