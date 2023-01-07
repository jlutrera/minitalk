NAME		=	libft.a
SRCS		=	${wildcard ./src/*.c}
HEADER		=	./include
CC 			=	gcc
FLAGS		=	-Wall -Wextra -Werror 
OBJS		=	${SRCS:.c=.o} 

${NAME}	:	${OBJS}
			@ar -rc ${NAME} ${OBJS}
.c.o	:
			@${CC} ${FLAGS} -I ${HEADER} -c $< -o ${<:.c=.o} 
all		:	${NAME}
clean 	:
			@rm -rf ${OBJS}
fclean 	: 	clean
			@rm -rf ${NAME}
re 		:	fclean all
.PHONY	:	fclean all clean re