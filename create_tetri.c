/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguirre <gio_aguirre19@yahoo.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 20:43:18 by gaguirre          #+#    #+#             */
/*   Updated: 2017/07/06 23:17:40 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		gridcpy(char *grid, char *file, int i)
{
	int j;

	j = 0;
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
				grid[j++] = '\0';
				return (i++);
			}
		}
		i++;
	}
}

char	**grid(char *file, int num)
{
	int i;
	int j;
	char **grid;

	i = 0;
	j = 0;
	grid = (char **)malloc(sizeof(char) * num + 1);
	if (!grid)
		return (0);
	while (file[i])
	{
		grid[j] = (char *)malloc(sizeof(char) * 16 + 1);
		if (!(grid[j]))
			return (0);
		gridcpy(grid[j], file[i], i);
		j++;
	}
	return (grid);
}
