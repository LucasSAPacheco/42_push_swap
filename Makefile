NAME = push_swap

HSRC	=	push_swap.h

# Inputs
SRCS = libft/add_front.c libft/add_last.c libft/find_last.c libft/ft_atoi.c \
		libft/ft_itoa.c libft/ft_putstr_fd.c libft/ft_strdup.c libft/ft_strlen.c \
		libft/new_node.c printf/srcs/picked_char.c printf/srcs/picked_i_or_d.c \
		printf/srcs/picked_ito_low_hex.c printf/srcs/picked_ito_up_hex.c \
		printf/srcs/picked_pointer.c printf/srcs/picked_str.c printf/srcs/picked_u.c \
		printf/ft_printf.c srcs/check_errors.c srcs/utils.c srcs/push_swap.c \
		srcs/choose_sort.c

OBJS	= $(SRCS:.c=.o)

# Compilation
CC		=	cc -Wall -Wextra -Werror
CFLAGS	=	-g3

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I.

${NAME}:	${OBJS} ${HSRC}
			ar -rcs push_swap.a ${OBJS}
			${CC} ${CFLAGS} ${SRCS} push_swap.a -o push_swap

clean:
	rm -f ${OBJS}
	rm -f ./srcs/${OBJS}
	rm -f ./libft/${OBJS}
	rm -f ./printf/${OBJS}
	rm -f ./printf/srcs/${OBJS}
	rm -f push_swap.a
	

fclean:    clean
		rm -f push_swap.a
		rm -f ${NAME}

re:		fclean all


.PHONY:    all clean fclean re