/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 12:56:37 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/10/10 15:46:55 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//stackb initiaten-------------------------------------------------------------------------------

//alle instructions schrijven--------------------------------------------------------------------

//misschien nog zoeken naar langste reeks opeenvolgende getallen---------------------------------

//unlink functie schrijven met return type *t_stack----------------------------------------------
//check of ie eerste of laatste staat en dan unlink

//freedata dubbelchecken-------------------------------------------------------------------------

//printfunctie-----------------------------------------------------------------------------------

//getallen met 000 ervoor------------------------------------------------------------------------

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
	write(2, "ERROR\n", 6);
	exit(1);
}

void	push_swap(char **input)
{
	t_stack	*stack;

	stack = initstack(input);
	sort(stack);
	//teststack(stack);
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

//void	teststack(t_stack *stack)
//{
//	while (stack->next != NULL)
//	{
//		printf("%d\n", stack->num);
//		stack = stack->next;
//	}
//	printf("end\n");
//}

void	sort(t_stack *stacka)
{
	t_data	*data;
	t_stack	*stackb;

	stackb = NULL;
	data = (t_data *)malloc(sizeof(t_data));
	data->sizea = ft_lstsize(stacka);
	ft_index(stacka, data);
	//while (data->sizea > 7)
	//{
	//	data->sizea = ft_lstsize(stacka);
	findmedians(data, data->sizea);
	//	//bigsort(stacka, data);
	//}
	//if (data->sizea <= 7)
	//{
	//	return ;
	//	//smallsort(stacka, data);
	//}
}//

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
		printf("stackindex :%d\n", min->index);
		printf("stacknum :%d\n\n", min->num);
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
	ft_putstr_fd("ERROR\n", 2);
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

void	findmedians(t_data *data, int size)
{
	int	high;

	high = size - 1;
	data->lmed = high / 3;
	data->rmed = high * 2 / 3;
}

//
//void	smallsort()
//{
//
//}
//
//void	bigsort()
//{
//
//}
//
//OPERATIONS===================================================================================

//void	swap(t_stack *stack)
//{
//	int	temp;
//	
//	temp = 0;
//	if (stack && stack->next)
//	{
//		temp = stack->next->num;
//		stack->next->num = stack->num;
//		stack->num = temp;
//	}
//}

//void	ss(t_stack *stacka, t_stack *stackb)
//{
//	swap(stacka);
//	swap(stackb);
//}
//
//void	push(t_stack *src, t_stack *dest)
//{
////unlink functie nodig voor lists---------------------------------------------------------------
//	if (src)
//		ft_lstadd_front(&dest, src);
//}
//
//void	rotate()
//{
//
//}
//
//void	rr()
//{
//	rotate(a);
//	rotate(b);
//}
//
//void	revrot()
//{
//
//}
//
//void	rrr()
//{
//	revrot(a);
//	revrot(b);
//}