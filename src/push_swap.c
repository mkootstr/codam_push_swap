/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 12:56:37 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/11/25 17:35:58 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//misschien nog zoeken naar langste reeks opeenvolgende getallen---------------------------------

//freedata dubbelchecken-------------------------------------------------------------------------

//printfunctie-----------------------------------------------------------------------------------

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**input;

	input = NULL;
	if (argc > 1)
	{
		input = parselist(argc, argv);
		push_swap(input);
	}
	else
		fatal();
	return (0);
}

char	**parselist(int argc, char *argv[])
{
	char	**list;
	int		i;

	i = 0;
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		while (list && list[i] != NULL && checkint(list[i]) == 1)
			i++;
		if (!list || list[i] != NULL)
			fatal();
	}
	else
		list = longinput(argc, argv);
	if (list)
		return (list);
	else
	{
		fatal();
		return (NULL);
	}
}

char **longinput(int argc, char *argv[])
{
	char	**list;
	int		i;
	int		j;

	list = NULL;
	i = 1;
	j = 0;
	list = malloc(argc * sizeof(char *));
	list[argc - 1] = NULL;
	while (i < argc && checkint(argv[i]) == 1)
	{
		list[j] = ft_strdup(argv[i]);
		if (list[j] == NULL)
			fatal();
		i++;
		j++;
	}
	if (i < argc && checkint(argv[i]) == 0)
		fatal();
	return (list);
}

int	checkint(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '-'|| (str[0] >= '0' && str[0] <= '9'))
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
			i++;
	}
	if (str && str[i] == '\0' && i < 12)
		return (1);
	else
		return (0);
}

void	fatal(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	push_swap(char **input)
{
	t_stack	*stack;

	stack = initstack(input);
	sort(stack);
}

t_stack	*initstack(char **input)
{
	t_stack	*stack;
	t_stack *next;
	int		num;
	int		i;

	stack = NULL;
	num = 0;
	i = 0;
	while (input && input[i] != NULL)
	{
		num = ft_atoi_check(input[i]);
		if (i == 0)
			stack = ft_lstnew(num);
		else
		{
			next = ft_lstnew(num);
			ft_lstadd_back(&stack, next);
		}
		i++;
	}
	freeinput(input);
	return (stack);
}

void	freeinput(char **input)
{
	int	i;

	i = 0;
	while (input && input[i])
	{
		free(input[i]);
		i++;
	}
	if (input)
		free(input);
}

void	sort(t_stack *stacka)
{
	t_data	*data;
	
	data = (t_data *)malloc(sizeof(t_data));
	data->heada = stacka;
	data->headb = NULL;
	data->sizea = ft_lstsize(stacka);
	ft_index(stacka, data);
	if (data->sizea > 5)
		radix(data);
	else
		smallsort(data);
	freeall(data, data->heada, data->headb);
}

void	ft_index(t_stack *stack, t_data *data)
{
	int	i;
	t_stack	*first;
	t_stack	*min;
	
	i = 0;
	min = stack;
	first = stack;
	while (i < data->sizea)
	{
		while (stack && stack->next != NULL)
		{
			if (stack->next->num < min->num && stack->next->index == -1)
				min = stack->next;
			if (min->num == stack->next->num && min != stack->next)
				ft_double(stack, data);
			stack = stack->next;
		}
		min->index = i;
		i++;
		stack = first;
		while (stack->index > -1 && stack->next != NULL)
			stack = stack->next;
		min = stack;
	}
}

void	ft_double(t_stack *stack, t_data *data)
{
	freeall(data, stack, NULL);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	freeall(t_data *data, t_stack *stacka, t_stack *stackb)
{
	if (stacka)
		ft_lstclear(stacka);
	if (stackb)
		ft_lstclear(stackb);
	if (data)
		free(data);
}

//RADIXSORT====================================================================================

int	issorted(t_data *data)
{
	t_stack *node;

	node = data->heada;
	while (node->next != NULL)
	{
		if (node->index > node->next->index)
			return (0);
		node = node->next;
	}
	return (1);
}

void	pushalla(t_data *data)
{
	while (data->headb != NULL)
		pa(data);
}

void	radix(t_data *data)
{
	int	bit;
	int	pos;
	int sizea;
	int check;

	bit = 0;
	pos = 0;
	sizea = ft_lstsize(data->heada);
	check = -1;
	while (issorted(data) == 0)
	{
		while (data->heada && data->heada->index != check)
		{
			bit = (data->heada->index & (1 << pos));
			if (bit == 0)
				pb(data);
			else
			{
				if (check == -1)
					check = data->heada->index;
				ra(data);
			}
		}
		pushalla(data);
		check = -1;
		pos++;
	}
}

//SMALLSORT====================================================================================

void	smallsort(t_data *data)
{
	if (data->sizea == 1)
		return ;
	if (data->sizea == 2)
		if (issorted(data) == 0)
			sa(data->heada);
	if (data->sizea == 3)
		sort_three(data);
	if (data->sizea == 4)
		sort_four(data);
	if (data->sizea == 5)
		sort_five(data);
}

void	sort_three(t_data *data)
{
	t_stack *node1;
	t_stack *node2;
	t_stack *node3;

	node1 = data->heada;
	node2 = node1->next;
	node3 = node2->next;
	while (issorted(data) == 0)
	{
		if ((node1->index < node3->index && node1->index > node2->index) ||\
		 (node3->index > node1->index && node3->index < node2->index) ||\
		  (node2->index < node1->index && node2->index > node3->index))
			sa(data->heada);
		else if (node1->index > node2->index)
			ra(data);
		else
			rra(data);
	}
}

void	optimize(int size, int pos, t_data *data)
{
	if (pos < (size / 2))
	{
		while (pos > 0)
		{
			ra(data);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(data);
			pos++;
		}
	}
}

void	sort_four(t_data *data)
{
	t_stack *lowest;
	t_stack *node;
	int		pos;
	int		i;

	node = data->heada;
	lowest = node;
	pos = 0;
	i = 0;
	while (node != NULL)
	{
		if (node->index < lowest->index)
		{
			lowest = node;
			pos = i;
		}
		node = node->next;
		i++;
	}
	optimize(4, pos, data);
	if (issorted(data) == 0)
	{
		pb(data);
		sort_three(data);
		pa(data);
	}
}

void	sort_five(t_data *data)
{
	t_stack *lowest;
	t_stack *node;
	int		pos;
	int		i;

	node = data->heada;
	lowest = node;
	pos = 0;
	i = 0;
	while (node != NULL)
	{
		if (node->index < lowest->index)
		{
			lowest = node;
			pos = i;
		}
		node = node->next;
		i++;
	}
	optimize(5, pos, data);
	if (issorted(data) == 0)
	{
		pb(data);
		sort_four(data);
		pa(data);
	}
}

//OPERATIONS===================================================================================

void	sa(t_stack *stacka)
{
	swap(stacka);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stackb)
{
	swap(stackb);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_data *data)
{
	swap(data->heada);
	swap(data->headb);
	ft_putstr_fd("ss\n",1);
}

void	pa(t_data *data)
{
	push(data->headb, data->heada, data, 'a');
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_data *data)
{
	push(data->heada, data->headb, data, 'b');
	ft_putstr_fd("pb\n", 1);
}

void	ra(t_data *data)
{
	rotate(data->heada, data, 'a');
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_data *data)
{
	rotate(data->headb, data, 'b');
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_data *data)
{
	rotate(data->heada, data, 'a');
	rotate(data->headb, data, 'b');
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_data *data)
{
	revrot(data->heada, data, 'a');
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_data *data)
{
	revrot(data->headb, data, 'b');
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_data *data)
{
	revrot(data->heada, data, 'a');
	revrot(data->headb, data, 'b');
	ft_putstr_fd("rrr\n", 1);
}

t_stack	*unlink_node(t_stack *stack, t_data *data, int ab)
{
	if (stack)
	{
		if (stack->prev == NULL)
		{
			if (stack->next)
                stack->next->prev = NULL;
			if (ab == 'a' && data->heada)
				data->heada = data->heada->next;
			if (ab == 'b' && data->headb)
				data->headb = data->headb->next;
		}
		if (stack->next == NULL && stack->prev)
			stack->prev->next = NULL;
		stack->prev = NULL;
		stack->next = NULL;
	}
	return (stack);
}

void	swap(t_stack *stack)
{
	int	tempnum;
	int tempindex;
	
	tempnum = 0;
	tempindex = 0;
	if (stack && stack->next)
	{
		tempnum = stack->next->num;
		tempindex = stack->next->index;
		stack->next->num = stack->num;
		stack->next->index = stack->index;
		stack->num = tempnum;
		stack->index = tempindex;
	}
}

void	push(t_stack *src, t_stack *dest, t_data *data, int ab)
{
	t_stack	*node;

	node = NULL;
	if (src)
	{
        if (ab == 'a')
		    node = unlink_node(src, data, 'b');
        else
            node = unlink_node(src, data, 'a');
        ft_lstadd_front(&dest, node);
		if (ab == 'a')
			data->heada = node;
		if (ab == 'b')
			data->headb = node;
	}  
}

void	revrot(t_stack *stack, t_data *data, int ab)
{
	t_stack	*node;

	node = NULL;
	if (stack)
	{
		node = ft_lstlast(stack);
		node = unlink_node(node, data, ab);
		if (ab == 'a')
        {
			ft_lstadd_front(&data->heada, node);
            data->heada = node;
        }
		if (ab == 'b')
        {
            ft_lstadd_front(&data->headb, node);
            data->headb = node;
        }
	}
}

void	rotate(t_stack *stack, t_data *data, int ab)
{
	t_stack *node;

	node = NULL;
	if (stack)
	{
		node = unlink_node(stack, data, ab);
		if (ab == 'a')
			ft_lstadd_back(&data->heada, node);
		if (ab == 'b')
			ft_lstadd_back(&data->headb, node);
	}
}
