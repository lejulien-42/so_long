clang ./srcs/*.c ./mlx/libmlx.a -D BUFFER_SIZE=8 -lXext -lX11 -fsanitize=address -g3
