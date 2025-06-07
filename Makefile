CC          = cc
CFLAGS      = -Wall -Wextra -Werror $(F_INC) -g3 

INC_LIB		= $(PATH_LIBFT)$(PATH_INC)
F_INC		= -I$(PATH_INC) -I$(INC_LIB)
LDFLAGS 	= -L$(PATH_LIBFT) -lft  
#-Wall -Wextra -Werror -g3 -fsanitize=address

RM          = @rm -rf

PATH_LIBFT  = libs/libft/
PATH_INC	= include/
PATH_SRC    = src/
PATH_OBJ    = build/

NAME            = push_swap
NAME_LIBFT      = libft.a
NAME_INC		= push_swap.h

LIBFT   		= $(PATH_LIBFT)$(NAME_LIBFT)

INC				=	$(PATH_INC)/$(NAME_INC)
SRC 			=	$(PATH_SRC)main.c \
					$(PATH_SRC)parsing.c \
					$(PATH_SRC)move_swap.c \
					$(PATH_SRC)move_rotate.c \
					$(PATH_SRC)move_reverse_rotate.c \
					$(PATH_SRC)move_push.c \
					$(PATH_SRC)utils_stack.c \
					$(PATH_SRC)push_swap.c \
					$(PATH_SRC)push_swap_find.c \
					$(PATH_SRC)push_swap_utils.c
OBJ	=	$(patsubst $(PATH_SRC)%.c, $(PATH_OBJ)%.o, $(SRC))

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(PATH_LIBFT)

$(PATH_OBJ)%.o : $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJ)  
	$(CC) $(CFLAGS) -c $< -o $@

$(PATH_OBJ):
	@mkdir -p $(PATH_OBJ)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(PATH_OBJ)
	$(MAKE) clean -C $(PATH_LIBFT)

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) fclean -C $(PATH_LIBFT)

re: fclean all

.PHONY: all clean fclean re
