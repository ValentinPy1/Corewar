##
## EPITECH PROJECT, 2021
## my hunter
## File description:
## makefile
##

SRC	= ../op.c \
		src/process.c \
		src/virtual_machine.c \
		src/ram.c \
		src/manage_ope.c \
		src/tools.c \
		src/get_option.c \
		src/register_load.c \
		src/end_cdt.c \
		src/get_real_args.c \
		src/display_memory.c \
		src/instructions/add.c	\
		src/instructions/and.c	\
		src/instructions/ld.c	\
		src/instructions/lld.c	\
		src/instructions/live.c	\
		src/instructions/or.c	\
		src/instructions/st.c	\
		src/instructions/sub.c	\
		src/instructions/xor.c	\
		src/instructions/zjmp.c \
		src/instructions/ldi.c	\
		src/instructions/lldi.c	\
		../asm/src/size_adjusters.c \
		../asm/src/get_op_index.c \
		src/instructions/sti.c \
		src/instructions/fork.c \
		src/special_loaders.c \

OBJ	=	$(SRC:.c=.o)

SMAIN	=	src/main.c

OMAIN	=	$(SMAIN:.c=.o)

NAME	=	corewar

CPPFLAGS	=	-I ../include/

LDFLAGS	=	-L ../my/ -lmy -lm

TESTFILES	=

all: $(NAME)

$(NAME):	libs $(OBJ) $(OMAIN)
	gcc -o $(NAME) $(OMAIN) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ) $(OMAIN)
	make clean -C ../my/

fclean:	clean
	$(RM) $(NAME)
	make fclean -C ../my/

re: fclean all

debug: CFLAGS	+=	-g3 -Wall -Wextra
debug: re

unit_test: CFLAGS	+=	-lcriterion
unit_test: $(OBJ)
	$(CC) -o unit_tests $(TESTFILES) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS) --coverage
	./unit_tests
	gcovr -r .

libs:
	make -C ../my

.PHONY: $(NAME) all clean fclean re libs
