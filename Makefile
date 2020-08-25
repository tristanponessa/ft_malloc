NAME = ls.a

SRC = read_file.c

OBJDIR = objs

CFLAGS = -g3

CC = gcc

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

OBJ = $(addprefix ${OBJDIR}/, $(SRC:.c=.o))

all:${NAME}
	@echo ${G}Success"   "[${NAME}]${X}

${NAME}: ${OBJ}
	@make -C libft/
	@ar rcs ${NAME} ${OBJ} 

${OBJDIR}/%.o : ./srcs/%.c
	@echo Compiling $@
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./. -I. -c -o $@ $<


clean:
	@echo clean libft...
	@make -C libft/ clean
	@echo clean objs...
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	@echo fclean libft...
	@make -C libft/ fclean
	@echo clean ${NAME}...
	@/bin/rm -f ${NAME} test

test:
	make && gcc ${CFLAGS} -o ls main.c ls.a libft/libft.a

re: fclean all

build: ${OBJ}

.PHONY: all clean fclean re test