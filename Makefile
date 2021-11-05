CC		= gcc

CFLAGS		= -Wall -Werror -Wextra

NAME		= push_swap

INC		= -I inc/

LIB_NAME	= libft/libft.a

SRCS_DIR	= srcs

SRCS_P		= db_list.c db_list2.c ft_errors.c ft_global_sort.c ft_init.c ft_parser1.c ft_parser2.c ft_print.c ft_push.c ft_reverse.c ft_rotate.c ft_sort1.c ft_sort2.c ft_sort3.c ft_sort4.c ft_sort_five.c ft_sort_three.c ft_sort_utils.c ft_stack.c ft_swap.c main.c

SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_P))

OBJS		= $(SRCS:.c=.o)

RM		= rm -f

$(NAME):	${OBJS}
		make -C libft
		${CC} ${OBJS} ${LIB_NAME} -o ${NAME}

%.o:		%.c
		${CC} ${CFLAGS} -c $< -o $@ $(INC)

all:		${NAME}

clean:
		${RM} ${OBJS}
		make clean -C libft

fclean:		clean
		${RM} ${NAME} ${LIB_NAME}

re:		fclean all

.PHONY:		all clean fclean re
