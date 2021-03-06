# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merlich <merlich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 21:18:17 by merlich           #+#    #+#              #
#    Updated: 2022/02/19 10:59:00 by merlich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	main.c error_handling.c \
			stack_functions_1.c stack_functions_2.c stack_functions_3.c \
			stack_operations_1.c stack_operations_2.c stack_operations_3.c \
			pre_sort.c pre_sort_2.c pre_sort_3.c sort.c sort_2.c sort_3.c \
			set_index.c scores.c \
			pre_radix_sort.c radix_sort.c sort_small_stack.c
			
OBJS_ADDR = objs/

OBJS	=	$(addprefix ${OBJS_ADDR}, ${SRCS:.c=.o})

D_FILES	=	${OBJS:.o=.d}

LIBFT	=	libft/libft.a

LIBFT_SRCS	=	libft/ft_isalpha.c libft/ft_isdigit.c \
				libft/ft_isalnum.c libft/ft_isascii.c \
				libft/ft_isprint.c libft/ft_strlen.c \
				libft/ft_memset.c libft/ft_bzero.c \
				libft/ft_memcpy.c libft/ft_memmove.c \
				libft/ft_strlcpy.c libft/ft_strlcat.c \
				libft/ft_toupper.c libft/ft_tolower.c \
				libft/ft_strchr.c libft/ft_strrchr.c \
				libft/ft_strncmp.c libft/ft_memchr.c \
				libft/ft_memcmp.c libft/ft_strnstr.c \
				libft/ft_atoi.c libft/ft_calloc.c \
				libft/ft_strdup.c libft/ft_substr.c \
				libft/ft_strjoin.c libft/ft_strtrim.c \
				libft/ft_split.c libft/ft_itoa.c \
				libft/ft_strmapi.c libft/ft_striteri.c \
				libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
				libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
				libft/ft_lstnew_bonus.c libft/ft_lstadd_front_bonus.c \
				libft/ft_lstsize_bonus.c \
				libft/ft_lstlast_bonus.c libft/ft_lstadd_back_bonus.c \
				libft/ft_lstdelone_bonus.c libft/ft_lstclear_bonus.c \
				libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c

LIBFT_OBJS	=	${LIBFT_SRCS:.c=.o}

CLANG		=	clang

CFLAGS		=	-Wall -Wextra -Werror -g -MD

RM			=	rm -rf

${OBJS_ADDR}%.o:	%.c
		mkdir -p ${OBJS_ADDR}
		${CLANG} ${CFLAGS} -c $< -o $@

all:	${NAME}

${LIBFT}: 	${LIBFT_SRCS} ${LIBFT_OBJS}
			make -C ./libft

${NAME}:	${OBJS} ${LIBFT} ${LIBFT_OBJS}
			${CLANG} ${OBJS} ${LIBFT} -o ${NAME}

-include ${D_FILES}

clean:
		make -C ./libft clean
		${RM} ${OBJS}
		${RM} ${D_FILES}

fclean:	clean
		make -C ./libft fclean
		${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
