/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 18:28:13 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/10/02 17:56:08 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstclear(t_stack *lst)
{
	if (lst)
	{
		lst = ft_lstlast(lst);
		while (lst && lst->prev)
		{
			lst = lst->prev;
			free(lst->next);
		}
		free(lst);
	}
}
