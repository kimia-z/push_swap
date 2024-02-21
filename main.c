/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kziari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:22:08 by kziari            #+#    #+#             */
/*   Updated: 2024/02/08 13:22:10 by kziari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>

void ft_is_sorted(t_stack *head)
{
	t_stack	*current;

	if (head == NULL || head->next == NULL)
		return;
	current = head;
	while (current->next != NULL)
	{
		if (*((int *)current->content) > *((int *)current->next->content))
			return;
		current = current->next;
	}
}

int main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack **stack_b;
	int *arr;

	if (argc < 2)
		print_error();
	arr = ft_check_arg(argc, argv);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (NULL);
	*stack_a = NULL;
	*stack_b = NULL;
	ft_put_in_stack(stack_a, arr);
	ft_is_sorted(&stack_a);
	ft_sort(&stack_a, &stack_b);
	ft_free()
	return (0);
}
