#include "fdf.h"

void	four_dots_setter(t_game *game, int i, int j)
{
	game->dots.x = (j - i) \
	* cos(game->angle * (PI / 180)) * (game->tile_size / 2) + game->constanta_x;
	game->dots.y = (j + i) * sin(game->angle * (PI / 180)) \
	* (game->tile_size / 2) + game->constanta_y - game->map[i][j] \
	* (game->tile_size / 2);
	game->dots.x1 = ((j + 1) - i) * cos(game->angle * (PI / 180)) \
	* (game->tile_size / 2) + game->constanta_x;
	game->dots.y1 = ((j + 1) + i) * sin(game->angle * (PI / 180)) \
	* (game->tile_size / 2) + game->constanta_y - game->map[i][j + 1] \
	* (game->tile_size / 2);
}

void	two_dots_setter(t_game *game, int i, int j)
{
	game->dots.x1 = ((j) - (i + 1)) \
	* cos(game->angle * (PI / 180)) \
	* (game->tile_size / 2) + game->constanta_x;
	game->dots.y1 = ((j) + (i + 1)) \
	* sin(game->angle * (PI / 180)) * (game->tile_size / 2) \
	+ game->constanta_y - game->map[i + 1][j] * (game->tile_size / 2);
}

void	first_draw(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->rows - 1)
	{
		j = 0;
		while (j < game->line_length - 1)
		{
			four_dots_setter(game, i, j);
			drawLine(game, color_manager(game->map[i][j + 1], game->map[i][j]));
			two_dots_setter(game, i, j);
			drawLine(game, color_manager(game->map[i + 1][j], game->map[i][j]));
			j++;
		}
		i++;
	}
}

void	second_draw(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = game->rows - 1;
	while (j < game->line_length - 1)
	{
		four_dots_setter(game, i, j);
		drawLine(game, color_manager(game->map[i][j + 1], game->map[i][j]));
		j++;
	}
	j = game->line_length - 1;
	i = 0;
	while (i < game->rows - 1)
	{
		four_dots_setter(game, i, j);
		two_dots_setter(game, i, j);
		drawLine(game, color_manager(game->map[i + 1][j], game->map[i][j]));
		i++;
	}
}

void	draw_grid(t_game *game)
{
	first_draw(game);
	second_draw(game);
}
