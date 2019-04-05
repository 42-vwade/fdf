
NAME		=	fdf
SRCDIR		=	source
FTLIBDIR	=	libft
MLXLIBDIR	=	minilibx
FDFLIB		=	libfdf.a
FTLIB		=	$(FTLIBDIR)/libft.a
MLXLIB		=	$(MLXLIBDIR)/libmlx.a

SRC	= $(addprefix $(SRCDIR)/, $(notdir $(filter %.c, $(filter-out .%, $(wildcard $(SRCDIR)/*)))))
OBJ	= $(notdir $(SRC:%.c=%.o))

CFLAGS	= -Wall -Werror -Wextra -lXext -lX11

all: $(NAME)

$(NAME): $(FDFLIB) $(FTLIB) $(MLXLIB)
	gcc -o $@ $(CFLAGS) -L $(FTLIBDIR) -lft -L $(MLXLIBDIR) -lmlx $(FDFLIB)

$(FDFLIB): $(OBJ)
	@ar -rc $@ $^
	@ranlib $@

$(OBJ): $(SRC)
	@gcc $(CFLAGS) $^

$(FTLIB): $(FTLIBDIR)
	@make -C $^

$(MLXLIB): $(MLXLIBDIR)
	@make -C $^

clean:
	@rm -rf $(OBJ)
	@cd $(FTLIBDIR) && make clean
	@cd $(MLXLIBDIR) && make clean

fclean: clean
	@rm -rf $(NAME) $(FDFLIB)
	@cd $(FTLIBDIR) && make fclean
	@cd $(MLXLIBDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re test v

v%: ;	@echo $* = $($*);

test:
	$(foreach var,	$(.VARIABLES),\
		$(info $(var) = $($(var))))
