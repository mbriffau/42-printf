# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/10 16:46:50 by achambon          #+#    #+#              #
#    Updated: 2017/09/28 23:46:55 by mbriffau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror -O2

LIBFT = libft

HEADER = includes

DIR_S = srcs

DIR_O = obj

COMPILED = $(LIBFT_COMPILED) $(SOURCES)

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

SOURCES =	ft_printf.c \
			parse_conversion.c \
			ft_error_management.c \
			conversion_specifier.c \
			init_conv.c \
			pointer.c \
			call_buffer.c \
			color.c \
			option.c \
			conv_c.c \
			pf_string.c \
			conv_d.c \
			conv_d2.c \
			conv_d3.c \
			conv_d4.c \
			conv_p.c \
			conv_p2.c \
			conv_s.c \
			conv_x.c \
			conv_x2.c \
			conv_x3.c \
			conv_x4.c \
			conv_b.c \
			conv_percent.c \
			no_conv.c \
			parse_wildcard.c

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "libftprintf.a \033[0;32mcreated.\033[0m"~

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@make clean -C $(LIBFT)
	@-/bin/rm -f $(OBJS)
	@-/bin/rm -rf $(DIR_O)
	@echo "All files .o have been \033[1;31mdeleted\033[0m."

fclean: clean
	@make fclean -C $(LIBFT)
	@-/bin/rm -f $(NAME)
	@echo "$(NAME) has been \033[1;31mdeleted\033[0m."

re : fclean all

.PHONY.: all clean fclean re