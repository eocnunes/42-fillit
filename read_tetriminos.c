/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetriminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 23:08:48 by enunes            #+#    #+#             */
/*   Updated: 2017/07/04 15:00:18 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define BUFF_SIZE 546
#include <stdio.h>
#include <unistd.h>

int		read_tetriminos(int const fd, char **file)
{
	int		rb;

	rb = read(fd, file, BUFF_SIZE);
	file[rb] = '\0';
	printf("%s\n", file);
	return (0);
}
