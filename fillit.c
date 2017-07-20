/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 22:44:05 by enunes            #+#    #+#             */
/*   Updated: 2017/07/19 15:35:59 by enunes           ###   ########.fr       */
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
	printf("File OK\n");
	return (0);
}
