/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_caller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 22:28:17 by enunes            #+#    #+#             */
/*   Updated: 2017/07/08 01:45:27 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		check_tetriminos(char *file)
{
	if (!check_chars(file))
		return (0);
	if (!check_width(file))
		return (0);
	if (!check_length(file))
		return (0);
	return (1);
}

char	**setup_puzzle(char *file)
{
	int		n;
	char	**puzzle;

	n = count_pieces(file);
	if (n > 26)
	{
		ft_putstr("error\n");
		return (0);
	}
	puzzle = (char **)malloc(sizeof(char) * n + 1);
	if (!puzzle)
		return (0);
	if (!get_pieces(file, puzzle))
		return (0);
	return (puzzle);
}
