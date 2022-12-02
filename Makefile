


CCF = cc -Wall -Wextra -Werror

SV_NAME = server
NAME = client

C_SRC = client.c
S_SRC = server.c
BONUST = _bonus

all:$(SV_NAME) $(NAME)

bonus:$(SV_NAME)$(BONUST) $(NAME)$(BONUST)

%:%.c
	$(CCF) $< -o $@

clean:
	rm -rf $(SV_NAME) $(SV_NAME)$(BONUST) $(NAME)  $(NAME)$(BONUST)

fclean:clean

re:fclean all bonus
