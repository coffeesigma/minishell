CC = cc
LIB_DIR = ./libft
LIB = libft.a
SRCSDIR_M = parse
SRCSDIR_B =
SRCS_M = main.c parse/tokenizer.c
SRCS_B = 
OBJS_M = $(addprefix mandatory/, ${SRCS_M:.c=.o})
OBJS_B = $(addprefix bonus/, ${SRCS_B:.c=.o})
NAME = minishell

ifdef WITH_BONUS
	OBJS = $(OBJS_B)
	SRCSDIRS = $(addprefix bonus/, $(SRCSDIR_B)) bonus
else
	OBJS = $(OBJS_M)
	SRCSDIRS = $(addprefix mandatory/, $(SRCSDIR_M)) mandatory
endif

DEPS = $(OBJS:.o=.d)
CFLAGS = $(addprefix -I,$(SRCDIRS)) -Wall -Wextra -Werror

.PHONY: all re clean fclean re bonus

all : $(NAME)

bonus :
	make WITH_BONUS=1

.c.o : %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEPS)

$(NAME) : $(OBJS) $(LIB_DIR)/$(LIB)
	$(CC) -o $@ $(OBJS) -L$(LIB_DIR) -lft

$(LIB_DIR)/$(LIB) :
	make -C $(LIB_DIR)
	make bonus -C $(LIB_DIR)

clean :
	rm -f $(OBJS)
	rm -f $(DEPS)
	make fclean -C $(LIB_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all