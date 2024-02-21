int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*node;

	node = lst;
	count = 0;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return (count);
}
void ft_sort_big(t_stack *head_a,t_stack *head_b)
{
	int	size;
	t_stack	*current;

	size = ft_lstsize(head_a);
	current = head_a;
	while (size > 0)
	{
		*(current->(int *)content) 
		size--;
	}
}

void ft_sort(t_stack *head_a, t_stack *head_b)
{
	int	size;

	size = ft_lstsize(head_a);
	if (size > 5)
		ft_sort_big(head_a, head_b);
	else
		ft_sort_small(head_a, head_b);
}
