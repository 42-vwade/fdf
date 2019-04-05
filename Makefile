
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
FF		= -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(FTLIB) $(MLXLIB) $(FDFLIB)
	gcc -o $@ $(CFLAGS) $(FF) $^ -L $(FTLIBDIR) -L $(MLXLIBDIR) -lmlx -lft -v

$(FDFLIB): $(OBJ)
	@ar -rc $@ $^
	@ranlib $@

$(OBJ): $(SRC)
	@make -C $(SRCDIR)

$(FTLIB): $(FTLIBDIR)
	@cd $^ && make all

$(MLXLIB): $(MLXLIBDIR)
	@cd $^ && make all

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
