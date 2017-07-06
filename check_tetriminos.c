/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:38:03 by enunes            #+#    #+#             */
/*   Updated: 2017/07/06 00:04:24 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_grid(char *file)
{
	int		i;
	int		grid;
	int		piece;
	int		line;

	i = 0;
	piece = 0;
	line = 4;
	while (file[i])
	{
		while (file[i] != '\n' && file[i + 1] != '\n')
		{
			grid = 0;
			if (file[i] == '.' || file[i] == '#')
				grid++;
			if (file[i] == '#')
				piece++;
			if (file[i] == '\n' && file[i + 1] != '\n')
			{
				if (grid != 4)
					return (0);
				grid = 0;
				line--;
			}
			i++;
		}
		if (line < 0)
			return (0);
	}
	if (piece != 4)
		return (0);
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

int		check_tetriminos(char *file)
{
	if (!check_chars(*file))
		return (0);
	if (!check_tetriminos(*file))
		return (0);
	return (1);
}
