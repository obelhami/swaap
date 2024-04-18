
#include "push_swap.h"

void    swap_a(t_stack_node **a)
{
    t_stack_node *tmp;

    if (*a && (*a)->next)
    {
        tmp = (*a)->next;
        (*a)->next = tmp->next;
        tmp->next = *a;
        *a = tmp;
    }
}
void    swap_b(t_stack_node **b)
{
    t_stack_node *tmp;

    if (*b && (*b)->next)
    {
        tmp = (*b)->next;
        (*b)->next = tmp->next;
        tmp->next = *b;
        *b = tmp;
    }
}

void    swap_s(t_stack_node **a, t_stack_node **b)
{
    swap_a(a);
    swap_b(b);
}

void    push_a(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *tmp;

    if (*b)
    {
        tmp = *b;
        *b = (*b)->next;
        tmp->next = *a;
        *a = tmp;
    }
}

void    push_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *tmp;

    if (*a)
    {
        tmp = *a;
        *a = (*a)->next;
        tmp->next = *b;
        *b = tmp;
    }
}

void    rotate_a(t_stack_node **a)
{
    t_stack_node *tmp;
    t_stack_node *tmp2;

    if (*a && (*a)->next)
    {
        tmp = *a;
        tmp2 = *a;
        *a = (*a)->next;
        while (tmp2->next)
            tmp2 = tmp2->next;
        tmp2->next = tmp;
        tmp->next = NULL;
    }
}

void    rotate_b(t_stack_node **b)
{
    t_stack_node *tmp;
    t_stack_node *tmp2;

    if (*b && (*b)->next)
    {
        tmp = *b;
        tmp2 = *b;
        *b = (*b)->next;
        while (tmp2->next)
            tmp2 = tmp2->next;
        tmp2->next = tmp;
        tmp->next = NULL;
    }
}

void    rotate_r(t_stack_node **a, t_stack_node **b)
{
    rotate_a(a);
    rotate_b(b);
}

void    reverse_rotate_a(t_stack_node **a)
{
    t_stack_node *tmp;
    t_stack_node *tmp2;

    if (*a && (*a)->next)
    {
        tmp = *a;
        tmp2 = *a;
        while (tmp2->next->next)
            tmp2 = tmp2->next;
        tmp2->next->next = tmp;
        *a = tmp2->next;
        tmp2->next = NULL;
    }
}

void    reverse_rotate_b(t_stack_node **b)
{
    t_stack_node *tmp;
    t_stack_node *tmp2;

    if (*b && (*b)->next)
    {
        tmp = *b;
        tmp2 = *b;
        while (tmp2->next->next)
            tmp2 = tmp2->next;
        tmp2->next->next = tmp;
        *b = tmp2->next;
        tmp2->next = NULL;
    }
}

void    reverse_rotate_r(t_stack_node **a, t_stack_node **b)
{
    reverse_rotate_a(a);
    reverse_rotate_b(b);
}