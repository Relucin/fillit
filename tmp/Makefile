CC = gcc
FLAGS = -Wall -Wextra -Werror -Llibft/ -lft -I.
NAME = fillit
TEST_DIR = tests
O_FILES = verify_input.c \
		  solver.c
T_FILES = valid_sample.fillit

all: libft.a $(NAME)

$(NAME): main.c $(O_FILES)
	@$(CC) $(FLAGS) $^ -o $@

libft.a:
	@make -C libft/ all

%.o: %.c
	@$(CC) $(FLAGS) $^ -o $@

run: $(NAME) $(T_FILES)


.PHONY: $(T_FILES)

$(T_FILES):
	@./$(NAME) $(TEST_DIR)/$@
clean:
	@rm -rf $(O_FILES)

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)

