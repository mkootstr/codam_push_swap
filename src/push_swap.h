/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 13:03:26 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/10/02 16:42:50 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../utils/utils.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_data
{
	struct s_stack	*heada;
	struct s_stack	*headb;
	int				sizea;
	int				sizeb;
}				t_data;

#endif
