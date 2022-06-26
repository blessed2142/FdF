#include "fdf.h"

void	map_maker_three(int *map, char *str, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		map[j] = ft_atoi(str + i);
		if (ft_atoi(str + i) > game->max_attitude)
			game->max_attitude = ft_atoi(str + i);
		else if (ft_atoi(str + i) < game->min_attitude)
			game->min_attitude = ft_atoi(str + i);
		j++;
		while (str[i] != ' ' && str[i] != '\0')
			i++;
		while (str[i] == ' ' && str[i] != '\0')
			i++;
	}
}

void	map_maker_two(t_game *game, t_list *head)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 0;
	j = 0;
	tmp = head;
	while (tmp)
	{
		map_maker_three(game->map[i], tmp->content, game);
		i++;
		tmp = tmp->next;
	}
}

void	map_maker(t_game *game, t_list *head)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->map = malloc(sizeof(int *) * game->rows);
	if (game->map == NULL)
		errors(3);
	while (i < game->rows)
	{
		game->map[i] = malloc(sizeof(int) * game->line_length);
		if (game->map[i] == NULL)
			errors(3);
		j = 0;
		while (j < game->line_length)
		{
			game->map[i][j] = 0;
			j++;
		}
		i++;
	}
	map_maker_two(game, head);
}
