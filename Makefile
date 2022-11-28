# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mkootstr <mkootstr@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/28 18:15:28 by mkootstr      #+#    #+#                  #
#    Updated: 2022/11/28 18:37:41 by mkootstr      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC_FILES =	src/check_input.c\
			src/operations.c\
			src/parser.c\
			src/printops1.c\
			src/printops2.c\
			src/printops3.c\
			src/push_swap.c\
			src/radixsort.c\
			src/smallsort.c\
			src/sort_utils.c

UTILS_FILES = utils/ft_atoi_check.c\
			utils/ft_lstadd_back.c\
			utils/ft_lstadd_front.c\
			utils/ft_lstclear.c\
			utils/ft_lstlast.c\
			utils/ft_lstnew.c\
			utils/ft_lstsize.c\
			utils/ft_putstr_fd.c\
			utils/ft_split.c\
			utils/ft_strdup.c\
			utils/ft_strlen.c

CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj/

SRC = $(addprefix $(OBJ_DIR),$(SRC_FILES:.c=.o))
UTILS = $(addprefix $(OBJ_DIR),$(UTILS_FILES:.c=.o))
OBJ = $(SRC) $(UTILS)

all: $(NAME)

$(OBJ_DIR)%.o: $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	mkdir -p $(OBJ_DIR)

$(NAME): directories $(OBJ)
	ar rs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
fclean:
	rm -f $(NAME)
re:
	fclean all

.PHONY: all clean fclean re
