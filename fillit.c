/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 22:44:05 by enunes            #+#    #+#             */
/*   Updated: 2017/07/27 18:13:06 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		setup_puzzle(char *file)
{
	int		num;
	char	**puzzle;

	num = count_pieces(file);
	if (num > 26)
		return (0);
	puzzle = (char **)ft_memalloc(sizeof(char *) * (num + 1));
	if (!puzzle)
		return (0);
	if (!get_pieces(file, puzzle))
		return (0);
	if (!valid_pattern(puzzle, num))
		return (0);
	setup_letters(puzzle, num);
	if (!solve(puzzle, num))
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	file[BUFF_SIZE];

	if (argc != 2)
		error();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error();
	else
	{
		ret = read_tetriminos(fd, file);
		if (ret < 0)
			error();
		else
		{
			if (!check_tetriminos(file))
				error();
			if (!setup_puzzle(file))
				error();
		}
	}
	return (0);
}
