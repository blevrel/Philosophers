# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blevrel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 10:32:08 by blevrel           #+#    #+#              #
#    Updated: 2022/08/13 12:32:30 by blevrel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =	srcs/philosophers.c \
		srcs/philosophers_utils.c \
		srcs/starting_routines.c \
		srcs/start_threads.c \
		srcs/start_simulation.c \
		srcs/get_time.c \
		srcs/check_nb_of_meals.c \
		srcs/print_message.c \
		srcs/one_philo.c \

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
	${CC} ${PTHREAD} ${CFLAGS} -c ${HEAD} $< -o ${<:.c=.o} -g

re: fclean all

${NAME}:${OBJS}
	${CC} ${PTHREAD} ${CFLAGS} ${OBJS} -o ${NAME} -g

.PHONY: bonus re clean fclean
