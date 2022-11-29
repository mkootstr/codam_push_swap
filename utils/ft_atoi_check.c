/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_check.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: marlou <marlou@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 20:06:38 by marlou        #+#    #+#                 */
/*   Updated: 2022/11/29 00:23:53 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../includes/functions.h"

void	afatal(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static long	ft_num(char *str, int x)
{
	int		j;
	long	num;

	j = 0;
	while (str[x] >= 48 && str[x] <= 57)
	{
		if (j == 0)
			num = str[x] - 48;
		else if (j <= 10 && num && str[x] <= '9' && str[x] >= '0')
			num = num * 10 + (str[x] - 48);
		x++;
		j++;
	}
	if (j != 0)
		return (num);
	else
		afatal();
	return (0);
}

static long	ft_minus(char *str, int a)
{
	int	x;

	if (str[a] == 45)
		x = -1;
	else
		x = 1;
	return (x);
}

int	ft_atoi_check(char *str)
{
	int		i;
	int		x;
	long	num;

	i = 0;
	if (str)
	{
		while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || \
		str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
			i++;
		x = ft_minus(str, i);
		if (str[i] == 45)
			i++;
		if ((str[i] == '0' && str[i + 1] != '\0') || (str[i] < '0' || \
		str[i] > '9') || (str[i] == '0' && x == -1))
			afatal();
		num = ft_num(str, i);
		num = x * num;
		if (ft_num(str, i) != 0 && num >= INT_MIN && num <= INT_MAX)
			return (num);
		if (num > INT_MAX || num < INT_MIN)
			afatal();
	}
	return (0);
}
