# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akasha <akasha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 14:45:49 by akasha            #+#    #+#              #
#    Updated: 2020/12/02 21:45:01 by akasha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

PRINTF_H =	-I includes/
LIBFT_H = 	-I src/libft/includes

COMP = gcc -Wall -Wextra -Werror $(LIBFT_H) $(PRINTF_H) -c -o

OBJ_DIR = obj/
SRC_DIR = src/
LIBFT = src/libft/

LIBFT_A = libft.a

SRC = ft_itoa_unsigned.c ft_itoa_hex.c \
	ft_write_percent.c ft_write_pointer.c ft_write_string.c \
	ft_printf.c ft_write_char.c ft_write_number.c \
	ft_parser.c ft_write_number_utils.c 

CFIND = $(SRC:%=$(SRC_DIR)%)

OFILE =	$(SRC:%.c=%.o)

OBJ = $(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cp $(LIBFT)$(LIBFT_A) .
	mv $(LIBFT_A) $(NAME)
	ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
	ranlib $@

$(OBJ): $(CFIND)
	make $(OFILE)

$(OFILE):
	@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
	rm -rf $(OBJ) *.out *.h.gch $(OBJ_DIR)
	make clean -C $(LIBFT)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re