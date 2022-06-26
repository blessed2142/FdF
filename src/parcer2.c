#include "fdf.h"

int	string_checker(char *str)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) || str[i] == '-')
			length++;
		while (str[i] != ' ' && str[i] != '\0')
			i++;
		while (str[i] == ' ' && str[i] != '\0')
			i++;
	}
	return (length);
}

void	line_legth_checker(t_list *head, t_game *game)
{
	t_list	*tmp;

	tmp = head;
	game->line_length = string_checker(tmp->content);
	tmp = tmp->next;
	while (tmp)
	{
		if (string_checker(tmp->content) != game->line_length)
			errors(2);
		tmp = tmp->next;
	}
}

void	downgrade(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->rows)
	{
		while (i < game->line_length)
		{
			game->map[j][i] -= game->min_attitude;
			i++;
		}
		j++;
	}
}
