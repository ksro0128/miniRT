CC = cc
CFLAGS = -Werror -Wall -Wextra
MLXFLAGS = -I. -Lmlx -lmlx -framework OpenGL -framework Appkit ./mlx/libmlx.a
ORIGIN_SRCS = src/main.c \
       src/gnl/get_next_line.c \
       src/gnl/get_next_line_utils.c \
	   src/parsing/init.c \
	   src/parsing/ft_split_set.c \
	   src/parsing/parsing.c \
	   src/parsing/ft_strtod.c \
	   src/parsing/set.c \
	   src/parsing/parsing_acl.c \
	   src/parsing/parsing_spplcy.c \
	   src/parsing/set_veiwport.c \
	   src/utils/utils.c \
	   src/utils/constructor.c \
	   src/utils/vec_utils_1.c \
	   src/utils/vec_utils_2.c \
	   src/utils/cal_utils.c \
	   src/draw/draw.c \
	   src/draw/my_mlx_pixel_put.c \
	   src/draw/apply_phonglighting.c \
	   src/draw/isshadow.c \
	   src/hit/check_hit.c \
	   src/hit/hit_sphere.c \
	   src/hit/hit_plane.c \
	   src/hit/hit_cylinder.c \
	   src/control/control.c
BONUS_SRCS = src_bonus/main.c \
       src_bonus/gnl/get_next_line.c \
       src_bonus/gnl/get_next_line_utils.c \
	   src_bonus/parsing/init.c \
	   src_bonus/parsing/ft_split_set.c \
	   src_bonus/parsing/parsing.c \
	   src_bonus/parsing/ft_strtod.c \
	   src_bonus/parsing/set.c \
	   src_bonus/parsing/parsing_acl.c \
	   src_bonus/parsing/parsing_spplcy.c \
	   src_bonus/parsing/parsing_hyperboloid.c \
	   src_bonus/parsing/set_veiwport.c \
	   src_bonus/parsing/parsing_normalmap.c \
	   src_bonus/parsing/set_bumpmap.c \
	   src_bonus/utils/utils.c \
	   src_bonus/utils/constructor.c \
	   src_bonus/utils/vec_utils_1.c \
	   src_bonus/utils/vec_utils_2.c \
	   src_bonus/utils/vec_utils_3.c \
	   src_bonus/utils/cal_utils.c \
	   src_bonus/draw/draw.c \
	   src_bonus/draw/my_mlx_pixel_put.c \
	   src_bonus/draw/apply_phonglighting.c \
	   src_bonus/draw/isshadow.c \
	   src_bonus/hit/check_hit.c \
	   src_bonus/hit/hit_sphere.c \
	   src_bonus/hit/hit_plane.c \
	   src_bonus/hit/hit_cylinder.c \
	   src_bonus/hit/hit_cylinder2.c \
	   src_bonus/hit/hit_hyperboloid.c \
	   src_bonus/control/control.c \
	   src_bonus/get_rgb/get_complementary_color.c \
	   src_bonus/get_rgb/get_rgb_plane.c \
	   src_bonus/get_rgb/get_bumpmap_plane.c \
	   src_bonus/get_rgb/get_rgb_sphere.c \
	   src_bonus/get_rgb/get_bumpmap_sphere.c \
	   src_bonus/get_rgb/get_rgb_cylinder.c \
	   src_bonus/get_rgb/get_bumpmap_cylinder.c \
	   src_bonus/get_rgb/get_rgb_hyperboloid.c \
	   src_bonus/get_rgb/get_bumpmap_hyperboloid.c
ORIGIN_OBJS = $(ORIGIN_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = miniRT

ifdef BONUS_TRUE
SRCS = $(BONUS_SRCS)
SRCS_OBJS = $(BONUS_SRCS:.c=.o)
else
SRCS = $(ORIGIN_SRCS)
SRCS_OBJS = $(ORIGIN_SRCS:.c=.o)
endif

all: $(NAME)

bonus :
	@make BONUS_TRUE=1

$(NAME): $(SRCS_OBJS)
	make bonus -C ./libft
	$(CC) $(CFLAGS) $(MLXFLAGS) $(SRCS_OBJS) ./libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(ORIGIN_OBJS)
	rm -f $(BONUS_OBJS)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean
	make all

.PHONY: all clean fclean re bonus