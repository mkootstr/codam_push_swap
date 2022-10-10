/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 13:03:26 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/10/10 11:31:26 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct	s_data
{
	struct s_stack	*heada;
	struct s_stack	*headb;
	int				sizea;
	int				sizeb;
	int				lmed;
	int				rmed;
}				t_data;

int	main(int argc, char *argv[]);
char	**parselist(int argc, char *argv[]);
char **longinput(int argc, char *argv[]);
int	checkint(char *str);
void	fatal(void);
void	push_swap(char **input);
t_stack	*initstack(char **input);
//void	teststack(t_stack *stack);
void	freeinput(char **input);
void	sort(t_stack *stacka);
void	ft_index(t_stack *stack, t_data *data);
void	ft_double(t_stack *stack, t_data *data);
void	freeall(t_data *data, t_stack *stacka, t_stack *stackb);
void	findmedians(t_data *data, int size);

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
void	ft_putstr_fd(char *s, int fd);


#endif

//gcc push_swap.c push_swap.h ../utils/*.c