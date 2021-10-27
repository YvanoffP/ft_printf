#SRCS_LIB		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
#					ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
#					ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
#					ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
#					ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
#					ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
#					ft_itoa.c ft_substr.c ft_strjoin.c ft_strmapi.c ft_striteri.c ft_strtrim.c \
#					ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
#					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
#				   	ft_lstmap.c	
#
#OBJS_LIB		= 	$(addprefix libft/, $(SRCS_LIB:.c=.o))

LIBFT_DIR		=	libft/

SRCS_PRINT		=	ft_nbrlen.c ft_printf.c ft_putnbr_base.c ft_detect_type.c

OBJS_PRINT		=	$(addprefix src/, $(SRCS_PRINT:.c=.o))

CC				= gcc $(CFLAGS)

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

.PHONY:			libft all clean fclean re bonus

all:			$(NAME)

$(NAME):		libft $(OBJS_PRINT)
				ar rcs $(NAME) $(LIBFT_DIR)/*.o $(OBJS_PRINT)
				@echo "Your LibftPrintf is done!"

libft:
				make -C $(LIBFT_DIR) all

clean:
				$(RM) $(OBJS_LIB) $(OBJS_PRINT)
				make -C $(LIBFT_DIR) clean

fclean:			clean
				$(RM) $(NAME)
				make -C $(LIBFT_DIR) fclean

re:				fclean $(NAME)
