/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:38:03 by enunes            #+#    #+#             */
/*   Updated: 2017/07/06 18:11:54 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <stdio.h>

int		check_line_width(char *file)
{
	int	i;
	int grid;

	i = 0;
	grid = 0;
	while (file[i])
	{
		if (file[i] == '.' || file[i] == '#')
			grid++;
		if (file[i] == '\n')
		{
			if (grid != 4)
				return (0);
			grid = 0;
			if (file[i + 1] == '\n')
			{
				grid = 4;
				i++;
			}
		}
		i++;
	}
	return (1);
}

//int		check

int		check_chars(char *file)
{
	int		i;

	i = 0;
	while (file[i])
	{
		if (file[i] != '#' && file[i] != '.' && file[i] != '\n')
			return (0);
		i++;
	}
	ft_putstr("Chars Checked\n");
	return (1);
}

int		check_tetriminos(char *file)
{
	if (!check_chars(file))
		return (0);
	if (!check_line_width(file))
		return (0);
	return (1);
}
