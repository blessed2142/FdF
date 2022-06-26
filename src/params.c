#include "fdf.h"

void	set_constx(t_game *game)
{
	game->constanta_x = game->rows * game->tile_size / 2;
}

void	set_tile_size(t_game *game)
{
	int	biggest;
	int	ts;

	biggest = 0;
	ts = 0;
	if (game->line_length > game->rows)
		biggest = game->line_length;
	else
		biggest = game->rows;
	ts = game->screen_width / biggest;
	while (ts % 4 != 0)
		ts -= 1;
	game->tile_size = ts - 28;
	if (game->tile_size < 1)
		game->tile_size = 8;
}

void	param_init(t_game *game)
{
	game->tile_size = 32;
	game->real_iso = 0;
	game->min_attitude = 2147483647;
	game->max_attitude = -2147483648;
	mlx_get_screen_size(&game->screen_width, &game->screen_height);
	game->constanta_x = 300;
	game->constanta_y = 100;
	game->angle = 39;
	set_tile_size(game);
	set_constx(game);
}
