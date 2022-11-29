/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radixsort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/28 16:53:19 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/11/29 19:17:10 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

static	int	sort_to_b(t_data *data, int pos, int check)
{
	int	bit;

	bit = 0;
	while (data->heada && data->heada->index != check)
	{
		bit = (data->heada->index & (1 << pos));
		if (bit == 0)
			pb(data);
		else
		{
			if (check == -1)
				check = data->heada->index;
			ra(data);
		}
	}
	return (check);
}

void	radix(t_data *data)
{
	int	pos;
	int	check;

	pos = 0;
	check = -1;
	while (issorted(data) == 0)
	{
		check = sort_to_b(data, pos, check);
		pushalla(data);
		check = -1;
		pos++;
	}
}
