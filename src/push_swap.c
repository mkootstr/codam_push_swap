/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 12:56:37 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/10/02 18:54:42 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//medians vinden met treesort?-------------------------------------------------------------------

//checken voor duplicates------------------------------------------------------------------------

//linked list ff maken en testen-----------------------------------------------------------------

//stackb initiaten-------------------------------------------------------------------------------

//alle instructions schrijven--------------------------------------------------------------------

//sorting algorithm uitzoeken--------------------------------------------------------------------

//misschien nog zoeken naar langste reeks opeenvolgende getallen---------------------------------

//freeinput schrijven----------------------------------------------------------------------------

//uitvinden of struct in utils.h en push_swap.h conflicting types worden-------------------------

//unlink functie schrijven met return type *t_stack----------------------------------------------
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct	s_data
{
	struct s_stack	*heada;
	struct s_stack	*headb;
	int				sizea;
	int				sizeb;
	struct s_stack	*lowmed;
	struct s_stack	*highmed;
}				t_data;

int	main(int argc, char *argv[])
{
	char	**input;
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
		while (list && list[i] != NULL && checkint(list[i] == 1))
			i++;
		if (!list || list[i] != NULL)
			fatal();
	}
	else
		list = longinput(argc, argv);
	if (list)
		return (list);
	else
		fatal();
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
	list[argc] == NULL;
	while (checkint(argv[i]) == 1 && i < argc)
	{
		list[j] = ft_strdup(argv[i]);
		if (list[j] == NULL)
			fatal();
		i++;
		j++;
	}
	if (checkint(argv[i]) == 0)
		fatal();
	return (list);
}

int	checkint(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-'|| (str[0] >= '0' && str[0] <= '9'))
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
			i++;
	}
	if (str[i] == '\0' && i < 12)
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
	while (stack && input && input[i] != NULL)
	{
		num = ft_atoi_check(input[i]);
		if (i = 0)
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

void	sort(t_stack *stacka)
{
	t_data	*data;
	t_stack	*stackb;

	data = (t_data *)malloc(sizeof(t_data));
	data->sizea = ft_lstsize(&stacka);
	if (data->sizea > 25)
//kijken wanneer bigsort wanneer smallsort
		bigsort(data, stacka);
	else
		smallsort(data, stacka);
	freeall(data, stacka, stackb);
}
//wat de fuck zijn pointers met linked lists

void	freeall(t_data *data, t_stack *stacka, t_stack *stackb)
{
	if (stacka)
		ft_lstclear(stacka);
	if (stackb)
		ft_lstclear(stackb);
	if (data)
		free(data);
}

void	smallsort()
{

}

void	bigsort()
{

}

//OPERATIONS===================================================================================

void	swap(t_stack *stack)
{
	int	temp;
	
	temp = 0;
	if (stack && stack->next)
	{
		temp = stack->next->num;
		stack->next->num = stack->num;
		stack->num = temp;
	}
}

void	ss(t_stack *stacka, t_stack *stackb)
{
	swap(stacka);
	swap(stackb);
}

void	push(t_stack *src, t_stack *dest)
{
//unlink functie nodig voor lists---------------------------------------------------------------
	if (src)
		ft_lstadd_front(&dest, src);
}

void	rotate()
{

}

void	rr()
{
	rotate(a);
	rotate(b);
}

void	revrot()
{

}

void	rrr()
{
	revrot(a);
	revrot(b);
}