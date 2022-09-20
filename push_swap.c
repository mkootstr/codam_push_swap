/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 12:56:37 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/09/20 19:10:01 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

//checken voor duplicates------------------------------------------------------------------------
//linked list ff maken en testen------------------------------------------------------------------------
//alle lst functies schrijven---------------------------------------------------------------------
//stackb initiaten------------------------------------------------------------------------
//alle instructions schrijven------------------------------------------------------------------------
//sorting algorithm uitzoeken------------------------------------------------------------------------
//misschien nog zoeken naar langste reeks opeenvolgende getallen------------------------------------
//freeinput schrijven----------------------------------------------------------------------
//freeall schrijven------------------------------------------------------------------------------
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
		{
			stack = ft_lstnew(num);
		}
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
	if (data->sizea > ???)
		bigsort(data, stacka);
	else
		smallsort(data, stacka);
	freeall(data, stacka, stackb);
}
//wat de fuck zijn pointers met linked lists

void	smallsort()
{

}

void	bigsort()
{

}



//OPERATIONS===================================================================================

void	swap()
{

}

void	ss()
{
	swap(a);
	swap(b);
}

void	push()
{

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