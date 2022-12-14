/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 18:27:44 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/11/28 17:44:03 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = ft_lstlast(*lst);
	if (temp && lst && new)
	{
		temp->next = new;
		new->prev = temp;
		new->next = NULL;
	}
	else if (temp == NULL && lst && new)
	{
		*lst = new;
		new->prev = NULL;
		new->next = NULL;
	}
}
