NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_conv.c \
		ft_printf_utils.c \
		ft_printf.c \
		main.c \


OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRC_bonus:.c=.o) 

RM = rm -f

all: $(NAME)

bonus : $(OBJS_B)
		ar -rs $(NAME) $^

$(NAME): $(OBJS)
	$(AR) -rcs $(NAME) $?

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all