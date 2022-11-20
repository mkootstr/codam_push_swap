/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testbits.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 19:42:44 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/11/20 14:50:38 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct	s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct	s_data
{
	struct s_stack	*heada;
	struct s_stack	*headb;
}				t_data;

int	zeropresent(t_data *data, int pos)
{
	int	bit;
	t_stack *node;

	node = data->heada;
	bit = 0;
	while (node != NULL)
	{
		bit = (node->index & (1 << pos));
		if (bit == 0)
			return (1);
		node = node->next;
	}
	return (0);
}

int	issorted(t_data *data)
{
	t_stack *node;

	node = data->heada;
	if (data->headb == NULL)
	{
		while (node->next != NULL)
		{
			if (node->index > node->next->index)
				return (0);
			node = node->next;
		}
		return (1);
	}
	else 
		return (0);
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

	bit = 0;
	pos = 0;
	while (issorted(data) == 0)
	{
		while (zeropresent(data, pos) == 1)
		{
			bit = (data->heada->index & (1 << pos));
			if (bit == 0)
				pb(data);
			else
				ra(data);
		}
		pushalla(data);
		pos++;
	}
}
