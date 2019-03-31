
NAME		=	fdf
SRCDIR		=	source
FTLIBDIR	=	libft
MLXLIBDIR	=	minilibx
FDFLIB		=	libfdf.a
FTLIB		=	$(FTLIBDIR)/libft.a
MLXLIB		=	$(MLXLIBDIR)/libmlx.a

SRC	= $(addprefix $(SRCDIR)/, $(notdir $(filter %.c, $(filter-out .%, $(wildcard $(SRCDIR)/*)))))
OBJ	= $(notdir $(SRC:%.c=%.o))

CFLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(FDFLIB) $(FTLIB) $(MLXLIB)
	touch $@

$(FDFLIB): $(OBJ)
	@ar -rc $@ $^
	@ranlib $@

$(OBJ): $(SRC)
	gcc $(CFLAGS) $^

$(FTLIB): $(FTLIBDIR)
	@cd $^ && make

$(MLXLIB): $(MLXLIBDIR)
	@cd $^ && make

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
	$(foreach var,$(.VARIABLES),$(info $(var) = $($(var))))
