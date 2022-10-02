/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 18:28:29 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/10/02 16:56:32 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node != NULL)
	{
		node->num = content;
		node->next = NULL;
		node->prev = NULL;
	}
	return (node);
}
