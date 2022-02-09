#include "push_swap.h"

void	ft_set_index(t_stack **head)
{
	int		i;
	int		stack_size;
	t_stack	*tmp;

	i = 0;
	stack_size = ft_stack_size(*head);
	tmp = *head;
	while (tmp)
	{
		tmp->index = i;
		tmp->score_a_r = i;
		tmp->score_a_rr = stack_size - i;
		i++;
		tmp = tmp->next;
	}
}

int	ft_min(int a, int b)
{
	int	res;

	if (a < b)
		res = a;
	else
		res = b;
	return (res);
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
