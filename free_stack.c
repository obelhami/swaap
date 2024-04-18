#include "push_swap.h"

void free_stack(t_stack_node **head)
{
    t_stack_node *tmp;

    while (*head)
    {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}