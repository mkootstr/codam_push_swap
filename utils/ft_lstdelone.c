/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 18:28:18 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/10/02 17:41:11 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstdelone(t_stack *lst)
{
	t_stack	*tempprev;
	t_stack	*tempnext;

	tempprev = NULL;
	tempnext = NULL;
	if (lst)
	{
		tempprev = lst->prev;
		tempnext = lst->next;
		if (tempnext != NULL)
			tempnext->prev = tempprev;
		if (tempprev != NULL)
			tempprev->next = tempnext;
		free(lst);
	}
}
