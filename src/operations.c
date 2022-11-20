/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 21:44:32 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/11/15 01:50:14 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	swapswap(t_stack *stacka, t_stack *stackb)
{
	swap(stacka);
	swap(stackb);
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

void	dblrotate(t_data *data)
{
	rotate(data->heada, data, 'a');
	rotate(data->headb, data, 'b');
}

void	dblrevrot(t_data *data)
{
	revrot(data->heada, data, 'a');
	revrot(data->headb, data, 'b');
}

int main(void)
{
    t_stack *node1;
    t_stack *node2;
    t_stack *node3;
    t_stack *node4;
    t_stack *node5;
    t_stack *node6;

    t_stack *tempa;
    t_stack *tempb;

    int count;

    t_data *data;

    node1 = (t_stack*)malloc(1 * sizeof(t_stack));
    node2 = (t_stack*)malloc(1 * sizeof(t_stack));
    node3 = (t_stack*)malloc(1 * sizeof(t_stack));
    node4 = (t_stack*)malloc(1 * sizeof(t_stack));
    node5 = (t_stack*)malloc(1 * sizeof(t_stack));
    node6 = (t_stack*)malloc(1 * sizeof(t_stack));

    data = (t_data*)malloc(1 * sizeof(t_data));
    
    node1->prev = NULL;
    node1->next = node2;
    node1->num = 1;
    node1->index = 1;
    node2->prev = node1;
    node2->next = node3;
    node2->num = 2;
    node2->index = 2;
    node3->prev = node2;
    node3->next = NULL;
    node3->num = 3;
    node3->index = 3;

    node4->prev = NULL;
    node4->next = node5;
    node4->num = 4;
    node4->index = 4;

    node5->prev = node4;
    node5->next = node6;
    node5->num = 5;
    node5->index = 5;

    node6->prev = node5;
    node6->next = NULL;
    node6->num = 6;
    node6->index = 6;

    data->heada = node1;
    data->headb = node4;
    printf("Voor:\n");
    printf("Top van stack a: %p\n", data->heada);
    printf("Top van stack b: %p\n\n", data->headb);
    printf("Adres node1: %p\n", node1);
    printf("Adres node2: %p\n", node2);
    printf("Adres node3: %p\n\n", node3);
    printf("Adres node4: %p\n", node4);
    printf("Adres node5: %p\n", node5);
    printf("Adres node6: %p\n\n", node6);

    //test swap a
    //swap(data->heada);

    //test swap b
    //swap(data->headb);

    //test double swap
    //swapswap(data->heada, data->headb);

    //test push a
    push(data->headb, data->heada, data, 'a');
   
    //test push b
    //push(data->heada, data->headb, data, 'b');
    
    //test rotate a
    //rotate(data->heada, data, 'a');

    //test rotate b
    //rotate(data->headb, data, 'b');

    //test double rotate
    //dblrotate(data);

    //test reverse rotate a
    //revrot(data->heada, data, 'a');

    //test reverse rotate b
    //revrot(data->headb, data, 'b');

    //test double reverse rotate
    //dblrevrot(data);




    tempa = data->heada;
    tempb = data->headb;
    count = 1;
    printf("\nNa:\n");
    printf("Top van stack a: %p\n", data->heada);
    printf("Top van stack b: %p\n\n", data->headb);
    printf("Stack A:\n");
    while (tempa)
    {
        printf("num en index %de node: %d, %d\n", count, tempa->num, tempa->index);
        tempa = tempa->next;
        count++;
    }
    printf("\n");
    count = 1;
    tempa = data->heada;
    while (tempa)
    {
        printf("prev en next %de node: %p, %p\n", count, tempa->prev, tempa->next);
        tempa = tempa->next;
        count++;
    }
    printf("\nStack B:\n");
    while (tempb)
    {
        printf("num en index %de node: %d, %d\n", count, tempb->num, tempb->index);
        tempb = tempb->next;
        count++;
    }
    printf("\n");
    count = 4;
    tempb = data->headb;
    while (tempb)
    {
        printf("prev en next %de node: %p, %p\n", count, tempb->prev, tempb->next);
        tempb = tempb->next;
        count++;
    }
    return (0);
}

//gcc operations.c push_swap.h ../utils/*.c