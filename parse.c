int ft_find_min(int *arr)
{
	int	min;
	int	i;

	i = 1;
	min = arr[0];
	while (arr[i])
	{
		if (min > arr[i])
			min = arr[i];
		i++;
	}
	return (min);
}

int *ft_simplify(int *arr)
{
	int	min;
	int	i;

	min = ft_find_min(arr);
	i = 0;
	while (arr[i])
	{
		arr[i] += min;
		i++;
	}
	return (arr);
}
int *is_negative(int *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] < 0)
			return (ft_simplify(arr));
		i++;
	}
	return (arr);
}
t_stack	*ft_lstnew(void *content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
///inja ro motmaen nistam chon ke arg lstnew(void *content) va ba int *arr chejori bayad node besazim
void ft_put_in_stack(t_stack **stack_a, int *arr)
{
	int	i;

	i = 0;
	arr = is_negative(arr);
	while (arr[i])
	{
		ft_lstadd_back(stack_a, ft_lstnew(arr[i]));
		i++;
	}
}