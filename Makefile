
NAME		=	fdf
SRCDIR		=	source/
BUILDDIR	= 	build/
OBJDIR		=	obj/
LIBFTDIR	=	libft
MLXLIBDIR	=	minilibx
FDFLIB		=	libfdf.a
LIBFT		=	$(LIBFTDIR)/libft.a
MLXLIB		=	$(MLXLIBDIR)/libmlx.a
CFILES		=	$(shell find ./source ! -name "._*" -regex ".*\\.[c]")
LCFILES		=	$(shell find ./libft ! -name "._*" -regex ".*\\.[c]")
MCFILES		=	$(shell find ./minilibx ! -name "._*" -regex ".*\\.[cm]")
INCLUDE		=	-I{$(MLXLIBDIR)}

SRC	= $(addprefix $(SRCDIR), $(notdir $(filter %.c, $(filter-out ._%, $(wildcard $(SRCDIR)*)))))
OBJ	= $(notdir $(SRC:%.c=%.o))

CFLAGS	= -O2 -Wall -Werror -Wextra
FF		= -framework OpenGL -framework AppKit

####	AUTO SETTING	########################################################

OBJDIR		:=	$(addprefix $(BUILDDIR), $(OBJDIR))
LIB			:=	$(addprefix $(BUILDDIR), $(dir $(LIBFT)))
OBJECTS		:=	$(addprefix $(OBJDIR), $(notdir $(CFILES:.c=.o)))
FDFLIB		:=	$(addprefix $(BUILDDIR), $(FDFLIB))

####	UNDER THE HOOD	########################################################

all: $(NAME)
	$^

test: $(LIBFT) $(MLXLIB) $(FDFLIB)


build: $(CFILES) $(LCFILES) $(MLXLIB)
	@gcc -g -o $(NAME) $(FF) $^ -L $(LIBFTDIR) -L $(MLXLIBDIR) -lmlx $(INCLUDE)

test:
	./$(NAME)

run:
	./$(NAME)

$(NAME): $(LIBFT) $(MLXLIB) $(FDFLIB)
	@gcc -o $@ $(CFLAGS) $(FF) $^ -L $(dir $(LIBFT)) -L $(dir $(MLXLIB)) -lmlx -lft

$(FDFLIB): $(OBJECTS) | $(OBJDIR) $(BUILDDIR)
	@ar rcu $@ $(OBJDIR)/*.o
	@ranlib $@
	@mv $@ $(BUILDDIR)

$(OBJECTS): $(CFILES) | $(OBJDIR)
	@make -C $(SRCDIR)
	@mv ./*.o $(OBJDIR)

$(MLXLIB): $(MLXLIBDIR)
	@cd $^ && make all

$(LIBFT): $(LIBFTDIR) | $(OBJDIR)
	@make all -C $(@D)

$(OBJDIR):
	@mkdir -p $@

$(BUILDDIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ)
	@cd $(LIBFTDIR) && make clean
	@cd $(MLXLIBDIR) && make clean

fclean: clean
	@rm -rf $(NAME) $(FDFLIB)
	@cd $(LIBFTDIR) && make fclean
	@cd $(MLXLIBDIR) && make clean

re: fclean all

.PHONY: all clean fclean re test v

v%: ;	@echo $* = $($*);

test:
	$(foreach var,	$(.VARIABLES),\
		$(info $(var) = $($(var))))
