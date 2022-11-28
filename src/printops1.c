/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printops1.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/28 16:38:50 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/11/28 17:59:55 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

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
	ft_putstr_fd("ss\n", 1);
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
