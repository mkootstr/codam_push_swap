/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   functions.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 13:03:26 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/11/28 17:57:49 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "structs.h"

void	push_swap(char **input);
void	sort(t_stack *stacka);

char	**parselist(int argc, char *argv[]);
char	**longinput(int argc, char *argv[]);
t_stack	*initstack(char **input);
void	ft_index(t_stack *stack, t_data *data);

int		checkint(char *str);
void	ft_double(t_stack *stack, t_data *data);
void	freeall(t_data *data, t_stack *stacka, t_stack *stackb);
void	freeinput(char **input);
void	fatal(void);

void	smallsort(t_data *data);
void	sort_three(t_data *data);
void	sort_four(t_data *data);
void	sort_five(t_data *data);

void	radix(t_data *data);

void	optimize(int size, int pos, t_data *data);
int		find_lowest(t_data *data);
int		issorted(t_data *data);
void	pushalla(t_data *data);

t_stack	*unlink_node(t_stack *stack, t_data *data, int ab);
void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dest, t_data *data, int ab);
void	revrot(t_stack *stack, t_data *data, int ab);
void	rotate(t_stack *stack, t_data *data, int ab);

void	sa(t_stack *stacka);
void	sb(t_stack *stackb);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

int		ft_atoi_check(char *str);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int content);
int		ft_lstsize(t_stack *lst);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);

#endif
