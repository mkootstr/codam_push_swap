/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/28 17:03:00 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/11/28 18:00:17 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

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

char	**longinput(int argc, char *argv[])
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

t_stack	*initstack(char **input)
{
	t_stack	*stack;
	t_stack	*next;
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

void	ft_index(t_stack *stack, t_data *data)
{
	int		i;
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
