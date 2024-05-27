# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hassaleh <hassaleh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 20:00:46 by hassaleh          #+#    #+#              #
#    Updated: 2024/05/27 20:43:21 by hassaleh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = server.c client.c mt_utils.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(NAME) server.c -o $(SERVER)
	@$(CC) $(CFLAGS) $(NAME) client.c -o $(CLIENT)

all: $(NAME)


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(OBJS) $(NAME) server client

re: clean all

.PHONY: all clean fclean re