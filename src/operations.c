/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/28 16:37:13 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/11/28 17:45:36 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

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
	int	tempindex;

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
	t_stack	*node;

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
