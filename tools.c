/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 13:03:21 by enunes            #+#    #+#             */
/*   Updated: 2017/07/20 21:04:20 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fillit.h>

int 	error(void)
{
		ft_putstr("error\n");
		exit(EXIT_FAILURE);
}

int		read_tetriminos(int const fd, char *file)
{
	int		rb;
	char	tmp[BUFF_SIZE + 1];

	rb = read(fd, tmp, BUFF_SIZE);
	tmp[rb] = '\0';
	ft_strcpy(file, tmp);
	return (0);
}

void	print_grid(char **grid, int num)
{
	int	i;

	i = 0;
	while(i < num)
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
		i++;
	}
}

void	del_grid(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int		solve(char **puzzle, int num)
{
	char	**grid;
	int		grid_size;
	
	grid_size = init_size(num);
	grid = create_grid(grid_size);
	if (!grid)
		return (0);
	while (!(recursion(grid, puzzle,  0, 0)))
	{

		grid_size++;
		grid = create_grid(grid_size);
		if (!grid)
			return (0);
	}
	print_grid(grid, grid_size);
	return (1);
}
