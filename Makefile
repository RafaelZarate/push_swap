MAKE = make -C
NAME_C = checker
NAME_P = push_swap
LIB = src/libft/
CFLAGS = -Wall -Wextra -Werror
CC = gcc

#When compiling. you need to add your .a lib
CFILES_C = src/libft/libft.a \
			src/checker/main_checker.c \
			src/checker/validator_parser.c \
			src/checker/list_functions.c \
			src/checker/operations_1.c \
			src/checker/operations_2.c \
			src/checker/utilities.c

CFILES_P = *.c

OBJECTS = $(CFILES:.c=.o)

#These options are here in case the lib needs to be recompiled.
#LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
LIBM = $(MAKE) $(LIB)
LIBR = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean

all: $(NAME_C)

$(NAME_C):
	@$(LIBM)
	@echo "LIBFT: Library successfully compiled"
	@$(CC) $(CFLAGS) -I. $(CFILES_C) -o $(NAME_C) 
	@echo "CHECKER: Successfull compilation"
	

clean:
	@$(LIBC)
	@echo "CHECKER: Removed .o files"

fclean: clean
	@$(LIBF)
	@echo "LIBFT: Removed .a"
	@/bin/rm -f $(OBJECTS) $(NAME_C)
	@echo "CHECKER: Removed exacutable"

re: fclean all
