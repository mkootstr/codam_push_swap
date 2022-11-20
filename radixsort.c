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
	int				higha;
	int				highb;
	int				lowa;
	int				lowb;
	int				lmed;
	int				rmed;
}				t_data;

void	sort_three(t_data *data)
{
	t_stack *node;
	node = data->heada;
	


}

int	issorted(t_data *data)
{
	int		checka;
	int		checkb;
	int		lowa;
	int		highb;

	checka = 0;
	checkb = 0;
	lowa = 0;
	highb = 0;


	return (0);
}


// 123
// 132 swap a, rra
// 213 swap a
// 231 rotate a
// 312 rra
// 321 swap a, rotate a