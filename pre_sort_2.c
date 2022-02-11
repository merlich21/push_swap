#include "push_swap.h"
#include <stdio.h>
void	ft_set_index_ra(t_stack **head_a)
{
	int		i;
	int		stack_size;
	t_stack	*elem;

	i = 0;
	stack_size = ft_stack_size(*head_a);
	elem = *head_a;
	while (elem)
	{
		elem->index = i;
		elem->score_a_r = i;
		elem->score_a_rr = stack_size - i;
		i++;
		elem = elem->next;
		// printf("!!!!!\nval = %d\nra = %d\n!!!!!\n", elem->value, elem->index);
	}
}

void	ft_set_index_rb(t_stack **head_b)
{
	int		i;
	int		stack_size;
	t_stack	*elem;

	i = 0;
	stack_size = ft_stack_size(*head_b);
	elem = *head_b;
	while (elem)
	{
		elem->index = i;
		elem->score_b_r = i;
		elem->score_b_rr = stack_size - i;
		i++;
		elem = elem->next;
		// printf("!!!!!\nval = %d\nra = %d\n!!!!!\n", elem->value, elem->index);
	}
}

static void	ft_fill_tab(int *tab, t_stack *head)
{
	int i;

	i = 0;
	while (head)
	{
		tab[i] = head->value;
		i++;
		head = head->next;
	}
}

static t_stack	*ft_get_mediana(int mediana, t_stack *head)
{
	while (head)
	{
		if (head->value == mediana)
			break ;
		head = head->next;
	}
	return (head);
}

t_stack	*ft_find_med(t_stack *head)
{
	t_stack	*med;
	int		*tab;
	int		mediana;
	int		len;


	if (!head)
		return (NULL);
	med = NULL;
	len = ft_stack_size(head);
	tab = malloc(sizeof(int) * ft_stack_size(head));
	ft_fill_tab(tab, head);
	ft_bubble_sort(tab, len);
	mediana = tab[len / 2];
	med = ft_get_mediana(mediana, head);
	free(tab);
	return (med);
}
