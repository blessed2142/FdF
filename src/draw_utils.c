#include "fdf.h"

void	set_black(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->screen_height)
	{
		x = 0;
		while (x < game->screen_width)
		{
			game->img.addr[(game->screen_width * y) + x] = 0;
			x++;
		}
		y++;
	}
}

int	color_manager(int first, int second)
{
	if (first || second)
		return (0x00FF00FF);
	return (0x00FFFFFF);
}

void	drawPixel(t_game *game, int x, int y, unsigned int color)
{
	game->img.addr[(game->screen_width * y) + x] = color;
}

void	draw_line_setter(t_game *game)
{
	game->line.deltaX = game->dots.x1 - game->dots.x;
	game->line.deltaY = game->dots.y1 - game->dots.y;
	if (fabs(game->line.deltaX) >= fabs(game->line.deltaY))
		game->line.longestLength = (fabs(game->line.deltaX));
	else
		game->line.longestLength = (fabs(game->line.deltaY));
	game->line.xIncrement = game->line.deltaX / game->line.longestLength;
	game->line.yIncrement = game->line.deltaY / game->line.longestLength;
	game->line.currentX = game->dots.x;
	game->line.currentY = game->dots.y;
}

void	drawLine(t_game *game, int color)
{
	int	i;

	i = 0;
	draw_line_setter(game);
	while (i < game->line.longestLength)
	{
		if (game->line.currentX > game->screen_width - 1 \
		|| game->line.currentX < 1 || game->line.currentY < 1 \
		|| game->line.currentY > game->screen_height - 1)
			break ;
		drawPixel(game, round(game->line.currentX), \
		 round(game->line.currentY), color);
		game->line.currentX += game->line.xIncrement;
		game->line.currentY += game->line.yIncrement;
		i++;
	}
}
