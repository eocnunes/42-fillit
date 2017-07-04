/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 22:44:05 by enunes            #+#    #+#             */
/*   Updated: 2017/07/04 15:00:15 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 546

#include <fcntl.h>
#include <libft.h>

int		read_tetriminos(int const fd, char **file);

int		main(int argc,char **argv)
{
	int 	fd;
	int		ret;
	char	*file[BUFF_SIZE];

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	else
	{
		ret = read_tetriminos(fd, &file);
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
