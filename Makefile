

CCF = cc -Wall -Wextra -Werror

SV_NAME = server
NAME = client

C_SRC = client.c
S_SRC = server.c

all:$(SV_NAME) $(NAME)

%:%.c
	$(CCF) $< -o $@

clean:
	rm -rf $(SV_NAME) $(NAME)

fclean:clean

re:fclean all
