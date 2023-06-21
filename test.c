#include "./push_swap.h"

void	ft_make_stack(t_list **list, int argc, char **argv)
{
	int		nbr;
	t_list	*new;

	nbr = 0;
	new = NULL;
	while (--argc > 1)
	{
		nbr = ft_atoi(argv[argc]);
		new = ft_lstnew(&nbr);
		ft_lstadd_front(list, new);
	}
}

int     main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	*tmp;
    
	stack_a = (t_list **)malloc(sizeof(t_list));
	if (!stack_a)
		return (0);
    stack_a = NULL;
	ft_make_stack(stack_a, argc, argv);
	tmp = *stack_a;
	while (tmp != NULL)
	{
		printf("%d", *((int *)(tmp->content)));
		tmp = tmp->next;
	}
	return (0);
}
