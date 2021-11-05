SRCS	= ft_atoi.c ft_isdigit.c ft_strlen.c ft_strcmp.c ft_strncmp.c ft_putstr_fd.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

NAME_LINUX	= libft.so

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra -I.

RM	= rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	 ar -rcs ${NAME} ${OBJS}

$(NAME_LINUX):	${OBJS}
		ar -rcs ${NAME_LINUX} ${OBJS}

all:	${NAME}

linux:	${NAME_LINUX}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME} ${NAME_LINUX}

re:	fclean all

.PHONY: all clean fclean re
