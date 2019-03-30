
NAME		=	fdf
SRCDIR		=	source
FTLIBDIR	=	libft
FDFLIB		=	libfdf.a
FTLIB		=	$(FTLIBDIR)/libft.a

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

clean:
	@rm -rf $(OBJ)
	@cd $(FTLIBDIR) && make clean

fclean: clean
	@rm -rf $(NAME) $(FDFLIB) $(FTLIB)
	@cd $(FTLIBDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re