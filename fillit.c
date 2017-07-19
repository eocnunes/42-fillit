/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 22:44:05 by enunes            #+#    #+#             */
/*   Updated: 2017/07/17 21:25:56 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fillit.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	file[BUFF_SIZE];

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		ft_putstr("error\n");
	else
	{
		ret = read_tetriminos(fd, file);
		if (ret < 0)
			ft_putstr("error\n");
		else
		{
			if (!check_tetriminos(file))
				ft_putstr("error\n");
			if (!setup_puzzle(file))
				ft_putstr("error\n");
		}
	}
	printf("File OK\n");
	return (0);
}
