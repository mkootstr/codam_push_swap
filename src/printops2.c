/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printops2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/28 16:41:04 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/11/28 17:45:55 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

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
