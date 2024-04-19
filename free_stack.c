#include "push_swap.h"

void free_stack(t_stack_node **a)
{
    t_stack_node *tmp;

    while (*a)
    {
        tmp = *a;
        *a = (*a)->next;
        free(tmp);
    }
    free(*a);
}
