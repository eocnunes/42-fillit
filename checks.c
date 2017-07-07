/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 22:28:17 by enunes            #+#    #+#             */
/*   Updated: 2017/07/06 23:13:14 by enunes           ###   ########.fr       */
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
