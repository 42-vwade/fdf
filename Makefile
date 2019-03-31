
NAME		=	fdf
SRCDIR		=	source
FTLIBDIR	=	libft
MLXLIBDIR	=	minilibx
FDFLIB		=	libfdf.a
FTLIB		=	$(FTLIBDIR)/libft.a
MLXLIB		=	$(MLXLIBDIR)/libmlx.a

SRC	= $(filter *.c, $(filter-out .*, $(notdir $(wildcard $(SRCDIR)/*))))
SRC	= $(SRCDIR)/$(SRC)
OBJ	= $(notdir $(SRC:%.c=%.o))

CFLAGS	= -c -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(FDFLIB) $(FTLIB)
	#	DELETE THIS	>>	##
	touch $@
	#	DELETE THIS	<<	##

$(FDFLIB): $(OBJ)
	@ar rc $@ $^
	@ranlib $@

$(OBJ): $(SRC)
	gcc $(CFLAGS) $^

$(FTLIB):
	@cd $(FTLIBDIR) && make

$(MLXLIB):
	@cd $(MLXLIBDIR) && make

clean:
	@rm -rf $(OBJ)
	@cd $(FTLIBDIR) && make clean
	@cd $(MLXLIBDIR) && make clean

fclean: clean
	@rm -rf $(NAME) $(FDFLIB)
	@cd $(FTLIBDIR) && make fclean
	@cd $(MLXLIBDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re