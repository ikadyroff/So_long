NAME	=	so_long

SRCS	=	so_long.c game/game_cmds.c game/game_cmds_2.c game/game_cmds_3.c\
			game/game_cmds_4.c validation/vld_cmds.c validation/vld_cmds_2.c\
			validation/vld_cmds_3.c validation/vld_errors.c gnl/get_next_line.c\
			gnl/get_next_line_utils.c

B_SRCS	=	bonus/b_so_long.c bonus/game/game_cmds.c bonus/game/game_cmds_2.c bonus/game/game_cmds_3.c\
			bonus/game/game_cmds_4.c bonus/game/game_cmds_5.c bonus/game/game_cmds_6.c bonus/game/game_cmds_7.c\
			bonus/validation/vld_cmds.c bonus/validation/vld_cmds_2.c bonus/validation/vld_cmds_3.c\
			bonus/validation/vld_errors.c gnl/get_next_line.c gnl/get_next_line_utils.c

HEADER	=	so_long.h

OBJ		=	$(SRCS:%.c=%.o)

B_OBJ	=	$(B_SRCS:%.c=%.o)

CC		=	gcc

LIB		=	libft/libft.a

FLAGS	=	-Wall -Wextra -Werror

MLX		=	-framework OpenGL -framework AppKit -lmlx

.PHONY	:	all clean fclean re libft

all		:	libft $(NAME)

libft	:
			@$(MAKE) -C libft/

$(NAME)	:	$(OBJ) $(HEADER)
				$(CC) $(FLAGS) $(OBJ) $(LIB) $(MLX) -o $(NAME)

%.o		:	%.c $(HEADER)
				$(CC) $(FLAGS) -c $< -o $@

bonus	:	libft $(B_OBJ)
				$(CC) $(FLAGS) $(B_OBJ) $(LIB) $(MLX) -o $(NAME)

clean	:
			@make clean -C ./libft
			@rm -rf $(OBJ) $(B_OBJ)

fclean	:	clean
				@make clean -C ./libft
				@$rm -rf $(NAME)

re		:	fclean all