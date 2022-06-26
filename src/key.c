#include "fdf.h"

void	key_handle(int key, t_game *game)
{
	if (key == 53)
		exit(0);
	else if (key == 24)
		game->tile_size += 4;
	else if (key == 27)
	{
		if (game->tile_size - 4 != 0)
			game->tile_size -= 4;
	}
	else if (key == 123)
		game->constanta_x -= 8;
	else if (key == 124)
		game->constanta_x += 8;
}

void	key_handle2(int key, t_game *game)
{
	if (key == 126)
	{
		game->constanta_y -= 8;
	}
	else if (key == 125)
	{
		game->constanta_y += 8;
	}
	else if (key == 6 && !game->real_iso)
	{
		game->angle += 1;
	}
	else if (key == 7 && !game->real_iso)
	{
		game->angle -= 1;
	}
}

int	key_press(int key, t_game *game)
{
	if (key == 53 || key == 24 || key == 27 || key == 123 || key == 124)
		key_handle(key, game);
	if (key == 126 || key == 125 || key == 6 || key == 7)
		key_handle2(key, game);
	else if (key == 15)
	{
		if (game->real_iso == 0)
			game->real_iso = 1;
		else
			game->real_iso = 0;
	}
	return (0);
}
