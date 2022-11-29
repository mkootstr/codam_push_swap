/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 12:56:37 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/11/29 17:57:06 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

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

void	push_swap(char **input)
{
	t_stack	*stack;

	stack = initstack(input);
	sort(stack);
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
