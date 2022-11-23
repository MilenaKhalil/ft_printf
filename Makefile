# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mikhalil <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/12 17:15:07 by mikhalil      #+#    #+#                  #
#    Updated: 2022/11/23 12:34:06 by mikhalil      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c \
	  ft_putuns_fd.c

LIBFT = ./libft/libft.a

OBJ = $(SRC:.c=.o)

#CFLAGS = -Wall -Werror -Wextra
CFLAGS = -Wall -Wextra

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	cp $(LIBFT) $(NAME)
	ar -rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all
