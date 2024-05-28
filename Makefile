# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hassaleh <hassaleh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 20:00:46 by hassaleh          #+#    #+#              #
#    Updated: 2024/05/28 18:13:36 by hassaleh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
B_NAME = minitalk_bonus.a
SERVER = server
CLIENT = client
B_CLIENT = client_bonus
B_SERVER = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = server.c client.c mt_utils.c
B_SRCS = server_bonus.c client_bonus.c mt_utils.c

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(NAME) server.c -o $(SERVER)
	@$(CC) $(CFLAGS) $(NAME) client.c -o $(CLIENT)

all: $(NAME)

bonus: $(B_OBJS)
	@ar -rc $(B_NAME) $(B_OBJS)
	@$(CC) $(CFLAGS) $(B_NAME) server_bonus.c -o $(B_SERVER)
	@$(CC) $(CFLAGS) $(B_NAME) client_bonus.c -o $(B_CLIENT)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(OBJS) $(NAME) $(B_OBJS) server client server_bonus client_bonus minitalk_bonus.a

re: clean all


.PHONY: all clean fclean re bonus