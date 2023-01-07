# Paths
L_PATH		=	./libft
S_PATH		=	./srcs
INCLUDE		=	./include

# Files
S			=	ft_server.c
C			=	ft_client.c
B_S			=	ft_server_bonus.c
B_C			=	ft_client_bonus.c
LIB_A		=	libft.a

# Sources and objects
S_SRC		=	$(S_PATH)/$(S)
C_SRC		=	$(S_PATH)/$(C)
B_S_SRC		=	$(S_PATH)/$(B_S)
B_C_SRC		=	$(S_PATH)/$(B_C)
S_OBJS		=	$(S_SRC:.c=.o)
C_OBJS		=	$(C_SRC:.c=.o)
B_S_OBJS	=	$(B_S_SRC:.c=.o)
B_C_OBJS	=	$(B_C_SRC:.c=.o)
OBJS		=	$(C_OBJS) $(S_OBJS) $(B_C_OBJS) $(B_S_OBJS) 

# Constant strings
GCC			=	gcc
LEAKS		= 	-g3 -fsanitize=address
FLAGS		=	-Wall -Wextra -Werror
S_NAME		=	server
C_NAME		=	client
B_S_NAME	=	server_bonus
B_C_NAME	=	client_bonus
LIB_NAME	=	$(L_PATH)/$(LIB_A)
NAME_A		=	ft

#  Colors
CYAN		=	\033[1;36m
YELLOW		=	\033[1;33m
GREEN		=	\033[0;32m
RESET		=	\033[0m

#  Rules
all			:	$(S_NAME) $(C_NAME)

$(S_NAME)	:	$(LIB_NAME) $(S_OBJS)
				@echo "Compiling program $(YELLOW) $(S_NAME) $(RESET).........\c"
				@$(GCC) $(FLAGS) $(LEAKS) -I$(INCLUDE) $(S_OBJS) -L $(L_PATH) -l $(NAME_A) -o $(S_NAME)
				@echo "$(GREEN) SUCCESS !$(RESET)"

$(C_NAME)	: 	$(LIB_NAME) $(C_OBJS)
				@echo "Compiling program $(YELLOW) $(C_NAME) $(RESET).........\c"
				@$(GCC) $(FLAGS) $(LEAKS) -I$(INCLUDE) $(C_OBJS) -L $(L_PATH) -l $(NAME_A) -o $(C_NAME)
				@echo "$(GREEN) SUCCESS !$(RESET)"

bonus		:	$(B_S_NAME) $(B_C_NAME)

$(B_S_NAME)	:	$(LIB_NAME) $(B_S_OBJS)
				@echo "Compiling program $(YELLOW) $(B_S_NAME) $(RESET).........\c"
				@$(GCC) $(FLAGS) $(LEAKS) -I$(INCLUDE) $(B_S_OBJS) -L $(L_PATH) -l $(NAME_A) -o $(B_S_NAME)
				@echo "$(GREEN) SUCCESS !$(RESET)"

$(B_C_NAME)	: 	$(LIB_NAME) $(B_C_OBJS)
				@echo "Compiling program $(YELLOW) $(B_C_NAME) $(RESET).........\c"
				@$(GCC) $(FLAGS) $(LEAKS) -I$(INCLUDE) $(B_C_OBJS) -L $(L_PATH) -l $(NAME_A) -o $(B_C_NAME)
				@echo "$(GREEN) SUCCESS !$(RESET)"

$(LIB_NAME)	:		
				@echo "Compiling library $(YELLOW) $(LIB_A) $(RESET)........\c"
				@$(MAKE) --no-print-directory -C $(L_PATH)
				@echo "$(GREEN) SUCCESS !$(RESET)"

.c.o		:
				@${GCC} -c $< -o ${<:.c=.o}

clean		:
				@rm -rf $(OBJS)
				@$(MAKE) --no-print-directory clean -C $(L_PATH) 
				@echo "$(CYAN)Removed all the \".o\" files$(RESET)"

fclean		:	clean
				@rm -rf $(S_NAME) $(C_NAME) $(B_S_NAME) $(B_C_NAME)
				@$(MAKE) --no-print-directory fclean -C $(L_PATH)
				@echo "$(CYAN)Removed the executables$(RESET)"

re			:	fclean all

.PHONY		:	all clean fclean re bonus