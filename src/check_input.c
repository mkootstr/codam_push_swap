/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/28 17:06:18 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/11/28 17:48:29 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int	checkint(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '-' || (str[0] >= '0' && str[0] <= '9'))
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
			i++;
	}
	if (str && str[i] == '\0' && i < 12)
		return (1);
	else
		return (0);
}

void	ft_double(t_stack *stack, t_data *data)
{
	freeall(data, stack, NULL);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	freeall(t_data *data, t_stack *stacka, t_stack *stackb)
{
	if (stacka)
		ft_lstclear(stacka);
	if (stackb)
		ft_lstclear(stackb);
	if (data)
		free(data);
}

void	freeinput(char **input)
{
	int	i;

	i = 0;
	while (input && input[i])
	{
		free(input[i]);
		i++;
	}
	if (input)
		free(input);
}

void	fatal(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
