//pop + add back
t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
t_stack *ft_before_lst(t_list *bef_lst)
{
	if (!bef_lst || bef_lst->next == NULL)
		return;
	while (bef_lst->next->next != NULL)
		bef_lst = bef_lst->next;
	return(bef_lst);
}

void ft_push(t_stack **stack, t_stack *node)
{
	t_stack	*temp;

	temp = *stack;
	node->next = temp;
	*stack = node;
}
t_stack *ft_pop(t_stack **stack)
{
	t_stack	*node;

	if(!*stack)
		return;
	node = *stack;
	*stack = node->next;
	node->next = NULL;
	return (node);
}
void ft_swap(t_stack **a)
{
	t_stack	*first_top;
	t_stack	*second_top;

	if (*a == NULL || *a->next == NULL)
		return;
	first_top = ft_pop(a);
	second_top = ft_pop(a);
	ft_push(a, first_top);
	ft_push(a, second_top);
}

void ft_swap_a(t_stack **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}
void ft_swap_b(t_stack **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}
void ft_swap_s(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
void ft_push_a(t_stack **a, t_stack **b)
{
	t_stack	*top_b;

	top_b = ft_pop(b);
	ft_push(a, top_b);
	write(1, "pa\n", 3);
}
void ft_push_b(t_stack **a, t_stack **b)
{
	t_stack	*top_a;

	top_a = ft_pop(a);
	ft_push(b, top_a);
	write(1, "pb\n", 3);
}
void ft_rotate(t_stack **x)
{
	t_stack	*temp;
	t_stack	*last_node;

	if(*x == NULL || *x->next == NULL)
		return;
	last_node = ft_lstlast(&x);
	temp = *x;
	*x = temp->next;
	last_node->next = temp;
	temp->next = NULL;
}
void ft_rotate_a(t_stack **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}
void ft_rotate_b(t_stack **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}
void ft_rotate_r(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
void ft_rev_rotate(t_stack **x)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*before_last;

	if(*x == NULL || *x->next == NULL)
		return;
	before_last = ft_before_lst(&x);
	last = ft_lstlast(&x);
	temp = *x;
	last->next = temp;
	*x = last;
	before_last->next = NULL;
}
void ft_rev_rotate_a(t_stack **a)
{
	ft_rev_rotate(a);
	write(1, "rra\n", 4);
}
void ft_rev_rotate_b(t_stack **b)
{
	ft_rev_rotate(b);
	write(1, "rrb\n", 4);
}
void ft_rev_rotate_r(t_stack **a, t_stack **b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	write(1, "rrr\n", 4);
}
