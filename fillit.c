/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 22:44:05 by enunes            #+#    #+#             */
/*   Updated: 2017/07/05 16:41:29 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fillit.h>

int		main(int argc,char **argv)
{
	int 	fd;
	int		ret;
	char	file[BUFF_SIZE];

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	else
	{
		ret = read_tetriminos(fd, file);
		printf("%s", file);
		if (ret == -1)
		{
			ft_putstr("error\n");
			return (0);
		}
//		else
//		{
//			check_tetriminos(file);
//		}
	}
	return (0);
}
