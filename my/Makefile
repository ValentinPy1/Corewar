##
## EPITECH PROJECT, 2021
## bootstrap
## File description:
## Makefile
##

SRC	=	str_utils.c \
		mem_setters.c \
		hashtable.c \
		htable_str.c \
		my_strcmp.c \
		hashtable.c \
		htable_str.c \
		s_init.c \
		get_substr.c \
		my_putstr.c \
		my_put_nbr.c \
		my_putchar.c \
		my_getnbr.c \
		my_getnbr_hexa.c \

OBJ	=	$(SRC:.c=.o)

SRCMAIN =	main.c

OBJMAIN =	$(SRCMAIN:.c=.o)

NAME	=	libmy.a

NAMETEST	=	test

CPPFLAGS	=	-I./include/

LDFLAGS	=	-L./ -lmy


all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(SRC) $(CPPFLAGS)
	ar rc $(NAME) $(OBJ)
	mkdir -p ../include
	cp include/my.h ../include/

clean:
	$(RM) $(OBJ)
	$(RM) *.o
	find . -name *~ -delete
	find . -name \#* -delete

fclean: clean
	$(RM) $(NAME)
	$(RM) unit*

test_main: $(OBJ) $(OBJMAIN)
	$(CC) -o $(OBJ) $(OBJMAIN)

$(NAMETEST):	 $(OBJ) $(OBJMAIN)
	$(CC) -o $(NAMETEST) $(OBJMAIN) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

debug: CFLAGS	+=	-g3 -Wall -Wextra
debug: test

unit_test: CFLAGS	+=	-lcriterion
unit_test: $(OBJ)
	$(CC) -o unit_tests $(TESTFILES) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS) --coverage
	./unit_tests
	gcovr -r .

libs:
	make -C lib/my

.PHONY: $(NAME) all clean fclean re libs test
