#include "fdf.h"

void	list_cleaner(t_list **head)
{	
	t_list	*tmp;
	t_list	*pred;

	tmp = *head;
	pred = NULL;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			pred->next = NULL;
			ft_lstclear(&tmp, &free);
		}
		else
		{
			pred = tmp;
			tmp = tmp->next;
		}
	}
}

void	list_free(t_list **head, int lst_size)
{
	int	i;

	i = 0;
	while (i++ < lst_size - 1)
		list_cleaner(head);
	ft_lstclear(head, &free);
}

t_list	*ft_lstnew_dope(void *content)
{
	t_list	*result;

	result = malloc(sizeof(t_list));
	if (result == NULL)
		errors(3);
	result->content = ft_strdup((char *)content);
	result->next = NULL;
	return (result);
}

void	ft_lstadd_back_dope(t_list **lst, t_list *new, char *str)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		if (str)
			free(str);
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->next = NULL;
	free(str);
}

void	parcer(t_game *game, char *argv)
{
	int		fd;
	t_list	*head;
	char	*str;
	t_list	*tmp;

	head = NULL;
	fd = open(argv, O_RDONLY);
	game->rows = 0;
	while (get_next_line(fd, &str))
	{
		ft_lstadd_back_dope(&head, ft_lstnew_dope(str), str);
		game->rows++;
	}
	free(str);
	tmp = head;
	line_legth_checker(tmp, game);
	map_maker(game, head);
	list_free(&head, ft_lstsize(head));
}
