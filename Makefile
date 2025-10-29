# Variables
NAME := philo
SRC_DIR := src
INCLUDE_DIR := include

CC := cc
CFLAGS := -Wall -Wextra -Werror -I$(INCLUDE_DIR)
RM := rm -f
RMDIR := rm -rf

# TODO
SRCS :=

OBJ_DIR := objs
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# General rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $$(dirname $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RMDIR) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test_data_race: CC := clang
test_data_race: CFLAGS += -fsanitize=thread -g
test_data_race: re

# TODO
test: test_data_race
./test.sh

.PHONY: all clean fclean re test_data_race test
