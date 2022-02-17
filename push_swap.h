/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:39:58 by merlich           #+#    #+#             */
/*   Updated: 2022/02/17 23:52:35 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define TYPE int
# define INIT_SIZE 10
# define MULTIPLIER 2
# define STACK_OVERFLOW -100
# define STACK_UNDERFLOW -101
# define OUT_OF_MEMORY -102

typedef struct s_stack
{
	TYPE			value;
	int				index;
	int				dec_index;
	int				bin_index;

	int				score_b_r;
	int				score_b_rr;
	int				score_a_r;
	int				score_a_rr;
	int				score_rr;
	int				score_rrr;

	int				ra_new;
	int				rb_new;
	int				rra_new;
	int				rrb_new;


	int				ra_rr;
	int				rb_rr;
	int				rra_rrr;
	int				rrb_rrr;
	int				ra_rrb;
	int				rb_rra;

	int				min_sum;
	struct s_stack	*next;
}	t_stack;

typedef struct push_swap
{
	t_stack	*min;
	t_stack	*med;
	t_stack	*max;

	t_stack	*head_a;
	t_stack	*head_b;

	t_stack	*minimal;
}	t_values;

void		ft_push(t_stack **head, TYPE value);
void		ft_push_elem(t_stack **head, t_stack *elem);
TYPE		ft_pop(t_stack **head);
t_stack		*ft_pop_elem(t_stack **head);
TYPE		ft_peak(const t_stack *head);
void		ft_delete_stack(t_stack **head);
int			ft_stack_size(t_stack *lst);
t_stack		*ft_stack_last(t_stack *lst);
t_stack		*ft_stack_last_but_one(t_stack *lst);
void		ft_check_isdigits(int argc, char **argv);
void		ft_check_duplicates(t_stack **head);
void		ft_error_msg(void);
void		ft_free_all(t_values *vals);

void		ft_sa(t_stack **head_a);
void		ft_sb(t_stack **head_b);
void		ft_ss(t_stack **head_a, t_stack **head_b);
void		ft_pa(t_stack **head_a, t_stack **head_b);
void		ft_pb(t_stack **head_b, t_stack **head_a);
void		ft_ra(t_stack **head_a);
void		ft_rb(t_stack **head_b);
void		ft_rr(t_stack **head_a, t_stack **head_b);
void		ft_rra(t_stack **head_a);
void		ft_rrb(t_stack **head_b);
void		ft_rrr(t_stack **head_a, t_stack **head_b);

int			ft_min(int a, int b);
int			ft_nonzero_min(int a, int b);
int			ft_max(int a, int b);

void		ft_set_index_ra(t_stack *head_a);
void		ft_set_index_rb(t_stack *head_b);
void		ft_set_index_rr(t_stack *head_b);
void		ft_find_scores_sum(t_stack *elem);

int			ft_is_sorted(t_stack *head);
int			ft_is_finally_sorted(t_stack *head);
void		ft_check_is_sorted(t_values *vals);

t_stack		*ft_get_scores(t_values *vals, t_stack *elem_b);
void		ft_set_scores(t_values *vals);

t_stack		*ft_find_max(t_stack *head);
t_stack		*ft_find_min(t_stack *head);
t_stack		*ft_find_med(t_stack *head);
t_stack		*ft_find_min_min_sum(t_stack *head);

void		ft_bubble_sort(int *tab, int len);
void		ft_triple_sort(t_stack **head);
void		ft_final_sort(t_values *vals);

void		ft_action_ra_rr(t_values *vals);
void		ft_action_rb_rr(t_values *vals);
void		ft_action_rra_rrr(t_values *vals);
void		ft_action_rrb_rrr(t_values *vals);
void		ft_action_ra_rrb(t_values *vals);
void		ft_action_rb_rra(t_values *vals);
void		ft_operation_parser(t_values *vals);

int			ft_dec_to_bin(int num);
void		ft_fill_tab(int *tab, t_stack *head);
void		ft_set_index(t_stack *head);
void		ft_sort_small_stack(t_values *vals);
void		ft_radix_sort(t_values *vals);
void	ft_print_stack(const t_stack *head);
#endif
