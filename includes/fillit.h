/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 14:27:59 by enunes            #+#    #+#             */
/*   Updated: 2017/07/20 00:46:47 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 1000

# include <unistd.h>
# include <fcntl.h>
# include <libft.h>

int			read_tetriminos(int const fd, char *file);
int			check_tetriminos(char *file);
int			check_chars(char *file);
int			check_width(char *file);
int			check_length(char *file);
int			count_pieces(char *file);
int			create_piece(char *grid, char *file);
int			get_pieces(char *file, char **puzzle);
int			setup_puzzle(char *file);
void		setup_letters(char **puzzle, int num);
int			valid_pattern(char **src, int pieces);
void		get_valid(char valid[20][14], int i);
int			bool_strstr(char *src, char *pat);
void		place_tetri(char **grid, char *tetri, int row, int col);
void		remove_tetri(char **grid, char *tetri, int row, int col);
int			check_place(char **grid, char *tetri, int row, int col);
char		**create_grid(int size);
int			init_size(int tetri);
int			solve(char **puzzle, int num);
void		print_grid(char **grid, int num);
void		del_grid(char **grid);
int			recursion(char **grid, char **puzzle, int row, int col);

#endif
