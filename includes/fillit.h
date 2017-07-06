/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 14:27:59 by enunes            #+#    #+#             */
/*   Updated: 2017/07/06 00:04:27 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 546

# include <unistd.h>
# include <fcntl.h>
# include <libft.h>

int		read_tetriminos(int const fd, char *file);
int		check_tetriminos(char *file);
int		check_chars(char *file);
int		check_grid(char *file);

#endif
