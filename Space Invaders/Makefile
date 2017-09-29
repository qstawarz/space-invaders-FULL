NAME    = app
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CC  = gcc
CFLAGS  = -W -Werror -Wall -Wextra
LDLIBS = -lSDL2 -lSDL2_image -lSDL2_ttf
RM  = rm -f
ECHO    = echo -e

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(INC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDLIBS)
	@$(ECHO) '\033[0;32m> Compiled\033[0m'

clean   :
	@$(RM) $(OBJ)
	@$(RM) *~
	@$(RM) \#*#
	@$(ECHO) '\033[0;31m> Directory cleaned\033[0m'

fclean  : clean
	@$(RM) $(NAME)
	@$(ECHO) '\033[0;31m> Remove executable\033[0m'

re  : fclean all
