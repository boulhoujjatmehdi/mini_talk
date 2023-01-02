

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

all: $(NAME)
	

$(NAME): $(C_OBJ) $(S_OBJ)
	

bonus: $(CB_OBJ) $(SB_OBJ)

%.o:%.c
	$(CCF) -c $< -o $@












# all:$(NAME)

# $(NAME):  $(SNAME) $(CNAME)

# bonus: $(SBNAME) $(CBNAME) 

# $(SNAME):server.c
# 	$(CCF) $< -o server
# $(CNAME):client.c
# 	$(CCF) $< -o client

# $(SBNAME):server_bonus.c
# 	$(CCF) $< -o server
# $(CBNAME):client_bonus.c
# 	$(CCF) $< -o client

clean:
	rm -rf $(C_OBJ) $(S_OBJ) $(CB_OBJ) $(SB_OBJ)

fclean:clean
	rm -rf client server

# re:fclean all

