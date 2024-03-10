NAME        := cub3D
CC        := gcc
FLAGS    := -g -Wall -Wextra -Werror 
MLX      := libmlx.a
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      lib/ft_atoi.c \
                          lib/ft_bzero.c \
                          lib/ft_calloc.c \
                          lib/ft_isalnum.c \
                          lib/ft_isalpha.c \
                          lib/ft_isascii.c \
                          lib/ft_isdigit.c \
                          lib/ft_isprint.c \
                          lib/ft_itoa.c \
                          lib/ft_lstadd_back.c \
                          lib/ft_lstadd_front.c \
                          lib/ft_lstclear.c \
                          lib/ft_lstdelone.c \
                          lib/ft_lstiter.c \
                          lib/ft_lstlast.c \
                          lib/ft_lstmap.c \
                          lib/ft_lstnew.c \
                          lib/ft_lstsize.c \
                          lib/ft_memchr.c \
                          lib/ft_memcmp.c \
                          lib/ft_memcpy.c \
                          lib/ft_memmove.c \
                          lib/ft_memset.c \
                          lib/ft_putchar_fd.c \
                          lib/ft_putendl_fd.c \
                          lib/ft_putnbr_fd.c \
                          lib/ft_putstr_fd.c \
                          lib/ft_split.c \
                          lib/ft_strchr.c \
                          lib/ft_strdup.c \
                          lib/ft_striteri.c \
                          lib/ft_strjoin.c \
                          lib/ft_strlcat.c \
                          lib/ft_strlcpy.c \
                          lib/ft_strlen.c \
                          lib/ft_strmapi.c \
                          lib/ft_strncmp.c \
                          lib/ft_strnstr.c \
                          lib/ft_strrchr.c \
                          lib/ft_strtrim.c \
                          lib/ft_substr.c \
                          lib/ft_tolower.c \
                          lib/ft_toupper.c \
                          lib/get_next_line/get_next_line.c \
                          lib/get_next_line/get_next_line_utils.c \
                          src/cub3d.c \
                          src/parse.c \
                          src/parse_details.c \
                          src/parse_map.c \
                          src/exit.c \
                          src/utils.c \
                          src/check.c \
                          src/check_texture.c \
                          src/check_fc.c \
                          src/init_player.c \
                          src/raycast.c \
                          src/raycast_2.c \
                          src/raycast_3.c \
                          src/move.c \
                          src/move_wasd.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

UNAME		:=	$(shell uname)

$(NAME): $(MLX) ${OBJS} 
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
			@echo "$(GREEN)$(NAME) created[0m ✔️"

$(MLX):
			@make -C ./mlx

all:		${NAME}

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"


fclean:		clean
			@ ${RM} ${NAME}
			@ rm -rf libmlx.a

			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


