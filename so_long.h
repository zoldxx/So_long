/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:34:18 by dberreby          #+#    #+#             */
/*   Updated: 2023/03/14 15:46:47 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "mlx-linux/mlx.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_game
{
	void			*mlx;
	void			*mlx_win;

	void			*wall;
	void			*grass;
	void			*perso;
	void			*coin;
	void			*door;
	void			*fond;
	void			*bad;

	char			**map;
	int				x_perso;
	int				y_perso;

	int				pocket;
	int				full_coin;
	unsigned int	move;

	int				nb_colonnes;
	int				nb_lignes;
}					t_game;

void				ft_exit_end(t_game *game);

void				i_picture(t_game *game);

void				my_mlx_pixel_put(t_data *data, int x, int y, int color);

char				**get_map(char *av);

void				lire_map(t_game *game);
int					parsing_map(char *av);
int					is_doable(char **map);

void				position_perso(t_game **game);

int					ft_input(int key, void *param);

void				init_game(t_game *game, char *av);

void				ft_exit(t_game *game);

void				inondation(char **test, int i, int k);

int					count_c_and_valid_char(char **map);

int					count_pe(char **map);

int					ft_printmove(t_game *game, int nb);

void				memset_game(t_game *game);
// GNL

char				*get_next_line(int fd, int flag);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *string, int searchedChar);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
size_t				ft_strlen(const char *theString);

// printf

int					ft_putchar(char c);
int					ft_putstr(char *str);
int					lenunbr(unsigned int n);
int					ft_unbr(unsigned int n);
int					convert(va_list set, char c);
int					ft_printf(const char *s, ...);

// formes geo

void				square(t_data *data, int x, int y, int color);
void				empty_square(t_data *data, int x, int y, int color);
void				triangle(t_data *data, int x, int y, int color);

#endif