#ifndef FDF_H
# define FDF_H

# include "./mlx/mlx.h"
# include <stdint.h>
# include <math.h>
# include <stdlib.h>
# include <float.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"

# define PI 3.14159265
# define TWO_PI 6.28318530

typedef struct s_dots
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}				t_dots;

typedef struct s_line
{
	float	deltaX;
	float	deltaY;
	float	longestLength;
	float	xIncrement;
	float	yIncrement;
	float	currentX;
	float	currentY;
}				t_line;

typedef struct s_img {
	void		*img;
	int			*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct s_game {
	void			*mlx;
	void			*mlx_win;
	t_img			img;
	t_dots			dots;
	t_line			line;
	int				rows;
	int				line_length;
	int				**map;
	int				tile_size;
	int				constanta_x;
	int				constanta_y;
	int				angle;
	int				min_attitude;
	int				max_attitude;
	int				screen_width;
	int				screen_height;
	int				real_iso;
}				t_game;

int		key_press(int key, t_game *game);
void	drawPixel(t_game *game, int x, int y, unsigned int color);
void	drawLine(t_game *game, int color);
void	parcer(t_game *game, char *argv);
void	errors(int code);
void	line_legth_checker(t_list *head, t_game *game);
void	map_maker(t_game *game, t_list *head);
void	draw_grid(t_game *game);
void	set_black(t_game *game);
void	draw_grid_real(t_game *game);
int		color_manager(int first, int second);
void	param_init(t_game *game);

#endif