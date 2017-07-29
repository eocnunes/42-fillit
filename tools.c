/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 13:03:21 by enunes            #+#    #+#             */
/*   Updated: 2017/07/29 15:05:58 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fillit.h>

int		error(void)
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
	while (i < num)
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
		i++;
	}
}

char	get_letter(char *str)
{
	while (*str == '.')
		str++;
	return (*str);
}
