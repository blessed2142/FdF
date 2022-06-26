#include "fdf.h"

void	print_menu(int fd)
{
	ft_putstr_fd("Buttons: \n", fd);
	ft_putstr_fd("Arrows: movement \n", fd);
	ft_putstr_fd("z, x: rotation \n", fd);
	ft_putstr_fd("+, -: zoom \n", fd);
	ft_putstr_fd("r: real(but not good looking) isometric projection\n", fd);
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->screen_width, \
	game->screen_height, "fdf");
}

void	image_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, game->screen_width, \
	game->screen_height);
	game->img.addr = (int *)mlx_get_data_addr(game->img.img, \
	&game->img.bpp, \
	&game->img.line_length, \
	&game->img.endian);
}

int	main_loop(t_game *game)
{
	set_black(game);
	if (!game->real_iso)
		draw_grid(game);
	else
		draw_grid_real(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		errors(1);
	parcer(&game, argv[1]);
	param_init(&game);
	print_menu(0);
	window_init(&game);
	image_init(&game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_hook(game.mlx_win, 2, 0, &key_press, &game);
	mlx_loop(game.mlx);
}
