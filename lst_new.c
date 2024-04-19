#include "push_swap.h"

t_stack_node	*new_node(long content)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->nbr = content;
	node->next = NULL;
	return (node);
}