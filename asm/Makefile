##
## EPITECH PROJECT, 2021
## my hunter
## File description:
## makefile
##

SRC	= ../op.c \
	src/compile_file.c \
	src/continue_writting_line.c \
	src/exec_strutc.c \
	src/fill_buffer.c \
	src/get_op_index.c \
	src/label.c \
	src/label_helper.c \
	src/label_reference.c \
	src/param_handlers.c \
	src/process_line.c \
	src/remove_final_new_line.c \
	src/size_adjusters.c \
	src/tools.c \
	src/write_binary.c \
	src/write_exec_at.c \
	src/write_header.c \
	src/write_instruct.c \
	src/error_handling_args_type.c \
	src/set_param_size.c \

OBJ	=	$(SRC:.c=.o)

SMAIN	=	src/main.c

OMAIN	=	$(SMAIN:.c=.o)

NAME	=	asm

CFLAGS +=	-Wall -Wextra -Werror

CPPFLAGS	=	-I ../include/

LDFLAGS	=	-L ../my/ -lmy

TESTFILES	= tests/test_endianness.c

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

debug: CFLAGS	+=	-g3
debug: re

unit_test: CFLAGS	+=	-lcriterion
unit_test: $(OBJ)
	$(CC) -o unit_tests $(TESTFILES) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS) --coverage
	./unit_tests
	gcovr -r .

libs:
	make -C ../my

.PHONY: $(NAME) all clean fclean re libs
