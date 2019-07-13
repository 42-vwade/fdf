
########################################################	AUX MAKEFILE	####
####	CONTROL PANEL	########################################################

CFILES		:=	$(shell find . ! -name "._*" -regex ".*\\.[c]")
OBJECTS		:=	$(notdir $(CFILES:%.c=%.o))

####	UNDER THE HOOD	########################################################

all: $(OBJECTS)
	@yes | mv -f $^ ../

$(OBJECTS): $(CFILES)
	@gcc -c -Wall -Wextra -Werror $^

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@cd .. && rm -rf $(OBJECTS)

re: fclean all

.PHONY: all clean fclean re