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

CFILES_P = src/libft/libft.a \
			src/push_swap/main_ps.c \
			src/push_swap/solver.c \
			src/push_swap/validator_parser.c \
			src/push_swap/stacks_ll_functions.c \
			src/push_swap/queue_ll_functions.c \
			src/push_swap/operations_ll_functions.c \
			src/push_swap/operations_1.c \
			src/push_swap/operations_2.c \
			src/push_swap/operations_3.c \
			src/push_swap/utilities.c \
			src/push_swap/algorithm_1.c

OBJECTS_C = $(CFILES_C:.c=.o)
OBJECTS_P = $(CFILES_P:.c=.o)

#These options are here in case the lib needs to be recompiled.
#LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
LIBM = $(MAKE) $(LIB)
LIBR = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean

all: $(NAME_C) $(NAME_P)

$(NAME_C):
	@$(LIBM)
	@echo "LIBFT: Library successfully compiled"
	@$(CC) $(CFLAGS) -I. $(CFILES_C) -o $(NAME_C) 
	@echo "CHECKER: Successfull compilation"
	
$(NAME_P):
	@$(LIBM)
	@echo "LIBFT: Library successfully compiled"
	@$(CC) $(CFLAGS) -I. $(CFILES_P) -o $(NAME_P) 
	@echo "PUSH_SWAP: Successfull compilation"

rps:
	@/bin/rm -f $(OBJECTS_P)
	@/bin/rm -f $(NAME_P)
	@$(LIBM)
	@$(CC) $(CFLAGS) -I. $(CFILES_P) -o $(NAME_P) 
	@echo "Push swap recompiled"

clean:
	@$(LIBC)
	@/bin/rm -f $(OBJECTS_C)
	@/bin/rm -f $(OBJECTS_P)
	@echo "CHECKER & PS: Removed .o files"

fclean: clean
	@$(LIBF)
	@echo "LIBFT: Removed .a"
	@/bin/rm -f $(NAME_C) $(NAME_P)
	@echo "CHECKER & PS: Removed exacutable"

re: fclean all
