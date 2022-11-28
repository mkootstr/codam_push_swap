/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printops3.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/28 16:42:16 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/11/28 17:46:04 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

void	rrr(t_data *data)
{
	revrot(data->heada, data, 'a');
	revrot(data->headb, data, 'b');
	ft_putstr_fd("rrr\n", 1);
}
