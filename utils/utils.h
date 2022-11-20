/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/02 16:38:05 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/11/14 22:11:34 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include "../src/push_swap.h"


//typedef struct	s_stack
//{
//	int				num;
//	struct s_stack	*next;
//	struct s_stack	*prev;
//}				t_stack;

int	ft_atoi_check(char *str);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack *lst);
void	ft_lstdelone(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int content);
int	ft_lstsize(t_stack *lst);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);

#endif