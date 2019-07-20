
NAME		=	fdf
SRCDIR		=	source/
BUILDDIR	= 	build/
OBJDIR		=	obj/
LIBFTDIR	=	libft
MLXLIBDIR	=
FDFLIB		=	libfdf.a
LIBFT		=	libft/libft.a
MLXLIB		=	.minilibx/libmlx.a
CFILES		=	$(shell find ./source ! -name "._*" -regex ".*\\.[c]")
LCFILES		=	$(shell find ./libft ! -name "._*" -regex ".*\\.[c]")

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

build: $(CFILES) $(LCFILES) $(MLXLIB)
	@gcc -g -o $(NAME) $(FF) $^ -L $(dir $(LIBFT)) -L $(dir $(MLXLIB)) -lmlx

$(NAME): $(LIBFT) $(MLXLIB) $(FDFLIB)
	@gcc -o $(NAME) $(CFLAGS) $(FF) $^ -L $(dir $(LIBFT)) -L $(dir $(MLXLIB)) -lmlx -lft

$(FDFLIB): $(OBJECTS) | $(OBJDIR) $(BUILDDIR)
	@ar rcu $@ $(OBJDIR)/*.o
	@ranlib $@
	@mv $@ $(BUILDDIR)

$(OBJECTS): $(CFILES) | $(OBJDIR)
	@make -C $(SRCDIR)
	@mv ./*.o $(OBJDIR)

$(MLXLIB): $(dir $(MLXLIB))
	@cd $^ && make all

$(LIBFT): $(dir $(LIBFT)) | $(OBJDIR)
	@make all -C $(@D)

$(OBJDIR):
	@mkdir -p $@

$(BUILDDIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ)
	@cd $(dir $(LIBFT)) && make clean
	@cd $(dir $(MLXLIB)) && make clean

fclean: clean
	@rm -rf $(NAME) $(FDFLIB)
	@cd $(dir $(LIBFT)) && make fclean
	@cd $(dir $(MLXLIB)) && make clean

re: fclean all

.PHONY: all clean fclean re test v

v%: ;	@echo $* = $($*);

test:
	$(foreach var,	$(.VARIABLES),\
		$(info $(var) = $($(var))))
