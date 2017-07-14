/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:38:03 by enunes            #+#    #+#             */
/*   Updated: 2017/07/10 22:51:53 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <stdio.h>

int		check_width(char *file)
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
			if (file[i + 1] == '\n')
				i++;
			if (grid != 4)
				return (0);
			grid = 0;
		}
		i++;
	}
	return (1);
}

int		check_length(char *file)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (file[i])
	{
		if (file[i] == '\n')
		{
			len++;
			if (file[i + 1] == '\n')
			{
				if (len != 4)
					return (0);
				len = 0;
				i++;
			}
		}
		i++;
	}
	return (1);
}

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
	return (1);
}
