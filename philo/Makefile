# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blevrel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 10:32:08 by blevrel           #+#    #+#              #
#    Updated: 2022/06/27 13:19:24 by blevrel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =	srcs/test_multithreading.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEAD = -I includes

RM = rm -f

PTHREAD = -pthread

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

.c.o:
	${CC} -pthread ${CFLAGS} -c ${HEAD} $< -o ${<:.c=.o} -g

re: fclean all

${NAME}:${OBJS}
	${CC} ${PTHREAD} ${CFLAGS} ${OBJS} -o ${NAME} -g

.PHONY: bonus re clean fclean
