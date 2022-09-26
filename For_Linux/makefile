NAME	=	so_long

SRCS	=	so_long.c game/game_cmds.c game/game_cmds_2.c game/game_cmds_3.c\
			game/game_cmds_4.c validation/vld_cmds.c validation/vld_cmds_2.c\
			validation/vld_cmds_3.c validation/vld_errors.c gnl/get_next_line.c\
			gnl/get_next_line_utils.c

HEADER	=	so_long.h

OBJ		=	$(SRCS:%.c=%.o)

CC		=	gcc

LIB		=	libft/libft.a

FLAGS	=	-Wall -Wextra -Werror

MLX		=	-lmlx -lXext -lX11

.PHONY	:	all clean fclean re libft

all		:	libft $(NAME)

libft	:
			@$(MAKE) -C libft/

$(NAME)	:	$(OBJ) $(HEADER)
				$(CC) $(FLAGS) $(OBJ) $(LIB) $(MLX) -o $(NAME)

%.o		:	%.c $(HEADER)
				$(CC) $(FLAGS) -c $< -o $@

clean	:
			@make clean -C ./libft
			@rm -rf $(OBJ)

fclean	:	clean
				@make clean -C ./libft
				@$(RM) $(NAME)

re		:	fclean all