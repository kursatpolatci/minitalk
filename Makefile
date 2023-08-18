NAME=serverclient.a

CC=gcc
CFLAGS=-Wall -Wextra -Werror
printf= ft_printf/libftprintf.a

CLIENT = client
SERVER = server

all: $(SERVER) $(CLIENT)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER):
	make -C ./ft_printf
	$(CC) $(CFLAGS) server.c $(printf) -o $@

$(CLIENT):
	make -C ./ft_printf
	$(CC) $(CFLAGS) client.c $(printf) -o $@

clean:
	make fclean -C ./ft_printf
	rm server client

fclean: clean

re: fclean all

.PHONY: all clean fclean re