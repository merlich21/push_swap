# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merlich <merlich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 21:18:17 by merlich           #+#    #+#              #
#    Updated: 2022/01/24 21:30:22 by merlich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	main.c

OBJS	=	${SRCS:.c=.o}

D_FILES	=	${SRCS:.c=.d}

CLANG		=	clang

CFLAGS		=	-Wall -Wextra -Werror -MD

RM			=	rm -rf

%.o:	%.c
		${CLANG} ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS}
			${CLANG} ${OBJS} -o ${NAME}

-include ${D_FILES}

clean:
		${RM} ${OBJS} &{D_FILES}

fclean:	clean
		${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
