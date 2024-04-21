#include "push_swap.h"

int	node_size(t_stack_node *lst)
{
	int	i;
	t_stack_node	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}