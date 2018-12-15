# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/07 14:46:57 by oriabyi           #+#    #+#              #
#    Updated: 2018/05/07 14:46:58 by oriabyi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:         all clean fclean re $(NAME)

CC = gcc
NAME = minishell
SRCDIR = src/
SRC =	$(SRCDIR)main.c				\
		$(SRCDIR)helpers.c			\
		$(SRCDIR)operations_env.c	\
		$(SRCDIR)builtin_cd.c		\
		$(SRCDIR)builtin_echo.c		\
		$(SRCDIR)auxiliary.c

CFLAGS = -Wall -Wextra -Werror
LIBDIR = ./libft
HEADER = -I ./includes -I $(LIBDIR)/libft.h
LIBINCL = -L. $(LIBDIR)/libft.a
OBJFOLD = ./.obj/
OBJ = $(addprefix $(OBJFOLD), $(SRC:.c=.o))

all:            $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBDIR) -f Makefile
	$(CC) $(CFLAGS) $(LIBINCL) $(HEADER) -o $(NAME) $(OBJ) 
	@echo "minishell: done"

$(OBJFOLD)%.o: %.c
	@mkdir -p $(OBJFOLD)$(SRCDIR)
	$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

clean:
	@rm -rf $(OBJFOLD)
	@make -C $(LIBDIR) -f Makefile clean
	@echo "objects removed"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) -f Makefile fclean
	@echo "binary removed"

