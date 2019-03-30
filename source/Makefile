
CFILES = $(filter-out .*, $(notdir $(wildcard *.c)))
OBJ = $(CFILES:%.c=%.o)

all: $(OBJ)
	@mv $^ ../

$(OBJ): $(CFILES)
	@gcc -c -Wall -Wextra -Werror $^

clean:
	@rm -rf $(OBJ)

fclean: clean

re: fclean all

.PHONY: all clean fclean re