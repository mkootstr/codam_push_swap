/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 18:28:06 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/10/02 17:17:00 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (lst && lst[0] && new)
	{
		new->next = lst[0];
		new->prev = NULL;
		lst[0]->prev = new;
		lst[0] = new;
	}
}
