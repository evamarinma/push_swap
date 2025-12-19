

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

int		init_stacks(t_list **stack_a, t_list **stack_b);
int		parse_input(t_list **stack_a, char **argv);
int		main(int argc, char **argv);
int		is_valid_num(char **data);
int		fill_stack(char **data, t_list **stack_a);
t_list	*ft_lstnew_int(int num);
void	ft_lstclear_int(t_list **lst);
t_list	*ft_lstnew_int(int num);
int		free_stacks(t_list **stack_a, t_list **stack_b);
void	free_arr(char **array);
int		count_args(t_list *stack_a);
int		check_duplicated(t_list *stack_a);
int		op_swap_a(t_list **stack_a);
int		op_swap_b(t_list **stack_b);
int		op_swap_ss(t_list **stack_a, t_list ** stack_b);
void	print_stack(t_list *stack);
int		op_push_a(t_list **stack_a, t_list **stack_b);
int		op_push_b(t_list **stack_a, t_list **stack_b);
int		op_rotate_a(t_list **stack_a);
int		op_rotate_b(t_list **stack_b);
int		op_rr(t_list **stack_a, t_list **stack_b);
int		op_re_rotate_a(t_list **stack_a);
int		op_re_rotate_b(t_list **stack_b);
int		op_re_rrr(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list *stack_a);
int		sort_two(t_list **stack_a);
int		sort_three(t_list **stack_a);
void	innit_index(t_list **stack_a, t_list **stack_b);
int		get_index(t_list **stack);
int		get_sorted(t_list **stack_a, t_list **stack_b);
int		large_sort(t_list **stack_a, t_list **stack_b);
void	extract_b(t_list **stack_a, t_list **stack_b);
int		eval_cost(t_list *stack_a, t_list *node, int len);
int		move_top(t_list **stack_a, t_list **stack_b, t_list *node, int len);
void	move_up(t_list **stack_a, t_list **stack_b, t_list *node);
void	move_down(t_list **stack_a, t_list **stack_b, t_list *node);
int		get_target(t_list *stack_a, int reference);
int		get_biggest_num(t_list *stack_a);
int		get_smallest_num(t_list *stack_a);
int		get_smallest_index(t_list *stack_a);
void	final_sort(t_list **stack_a);
int		error_output(void);

#endif