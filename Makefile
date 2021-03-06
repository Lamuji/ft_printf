NAME = libftprintf.a
AR = ar
ARFLAGS = rc
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = $(addprefix libft/,) \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strlen.c \
	   ft_strdup.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strnstr.c \
	   ft_strncmp.c \
	   ft_atoi.c \
	   ft_strlcpy.c \
	   ft_calloc.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strmapi.c \
	   ft_split.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_itoa.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putnbr_fd.c \
	   ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

SRCS =	ft_conv.c \
		ft_printf_utils.c \
		ft_printf.c \
		ft_check_flags.c \
		print_char.c \
		print_d_i.c \
		print_str.c \
		print_u.c \
		print_Xx.c \
		print_p.c \
		print_str.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	make bonus -C libft/
	mv libft/libft.a ./libftprintf.a
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

prog: libftprintf.a
	$(CC) -o prog main.c $(NAME)
clean:
	$(RM) $(OBJS) 
	make clean -C libft/

fclean:
	$(RM) $(NAME)
	make fclean -C libft/

re: fclean all