NAME=ft_ls

SRCS_PATH = src/
OBJ_PATH  = obj/

FLAGS = -Wall -Wextra -Werror

LSRC=./libft/

LLSRC=./libft/libft/

SRCS_NAME=main.c \
parse_args.c \
initters.c \
parse_right.c \
setters.c \
sortfile.c \
helppers.c \
sortter.c \
sorthelppers.c \
sorttrcap.c \
free.c \
free2.c \
printhandler.c \
printter.c \
printtrcap.c \
printfile.c \
sortparam.c \
utils.c 

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L $(LSRC) -L $(LLSRC) -lft -lftprintf

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@gcc $(FLAGS) -c -I includes/ $< -o $@ -c

clean:
	@make clean -C libft
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re:fclean all
