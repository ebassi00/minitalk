SRCS_CLIENT = client.c
SRCS_SERVER = server.c
LIBFT = ./libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: client server

bonus: client server

$(LIBFT):
	$(MAKE) -C ./libft

client: $(LIBFT)
	$(CC) $(FLAGS) $(LIBFT) $(SRCS_CLIENT) -o client

server: $(LIBFT)
	$(CC) $(FLAGS) $(LIBFT) $(SRCS_SERVER) -o server

clean:
	$(MAKE) clean -C ./libft

fclean:	clean
	rm -f server client
	$(MAKE) fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re bonus