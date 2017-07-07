/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 22:44:05 by enunes            #+#    #+#             */
/*   Updated: 2017/07/06 17:34:07 by enunes           ###   ########.fr       */
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
		ft_putstr("error1\n");
		return (0);
	}
	else
	{
		ret = read_tetriminos(fd, file);
	//	printf("%s", file);
		if (ret == -1)
		{
			ft_putstr("error2\n");
			return (0);
		}
		else
		{
			if (!check_tetriminos(file))
			{
				ft_putstr("error3\n");
				return (0);
			}
			else
				printf("File OK\n");
		}
	}
	return (0);
}
