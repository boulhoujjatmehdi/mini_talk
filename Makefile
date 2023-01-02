CCF = cc -Wall -Wextra -Werror

NAME = name

C_SRC = client.c
C_OBJ = $(C_SRC:.c=.o)

S_SRC = server.c
S_OBJ = $(S_SRC:.c=.o)

CB_SRC = client_bonus.c
CB_OBJ = $(CB_SRC:.c=.o)

SB_SRC = server_bonus.c
SB_OBJ = $(SB_SRC:.c=.o)

%.o:%.c
	$(CCF) -c $< -o $@

all: $(NAME)

$(NAME): client server

client: $(C_OBJ)
	$(CCF) $(C_OBJ) -o client


server:$(S_OBJ)
	$(CCF) $(S_OBJ) -o server

bonus: bonus_client bonus_server

bonus_client: $(CB_OBJ)
	$(CCF) $(CB_OBJ) -o client

bonus_server: $(SB_OBJ)
	$(CCF) $(SB_OBJ) -o server
clean:
	rm -rf $(C_OBJ) $(S_OBJ) $(CB_OBJ) $(SB_OBJ)

fclean:clean
	rm -rf client server

re:fclean all

