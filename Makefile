NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

INC_DIR     = include
M_DIR       = src_mandatory
B_DIR       = src_bonus
S_DIR       = src_shared

INC         = -I $(INC_DIR) -I $(LIBFT_DIR)

COMMON_SRCS = $(S_DIR)/parse_argv.c \
              $(S_DIR)/index_stack.c \
              $(S_DIR)/node_utils.c \
              $(S_DIR)/config_utils.c \
              $(S_DIR)/math.c \
              $(S_DIR)/is_sorted.c

SRCS        = $(M_DIR)/push_swap.c \
              $(M_DIR)/set_disorder.c \
              $(M_DIR)/simple_sort.c \
              $(M_DIR)/medium_sort.c \
              $(M_DIR)/complex_sort.c \
              $(M_DIR)/display_bench.c \
              $(M_DIR)/ops_first.c \
              $(M_DIR)/ops_second.c \
              $(M_DIR)/ops_third.c \
              $(COMMON_SRCS)

BONUS_SRCS  = $(B_DIR)/checker.c \
              $(B_DIR)/get_next_line.c \
              $(B_DIR)/get_next_line_utils.c \
              $(B_DIR)/ops_first_bonus.c \
              $(B_DIR)/ops_second_bonus.c \
              $(B_DIR)/ops_third_bonus.c \
              $(COMMON_SRCS)

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re