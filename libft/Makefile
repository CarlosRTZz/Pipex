# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 12:41:54 by cortiz            #+#    #+#              #
#    Updated: 2023/03/26 18:48:45 by carlosortiz      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_atoi.c	\
	ft_isascii.c	\
	ft_memcmp.c		\
	ft_strchr.c		\
	ft_strncmp.c	\
	ft_toupper.c	\
	ft_bzero.c		\
	ft_strjoin.c	\
	ft_isdigit.c	\
	ft_memcpy.c		\
	ft_strlcat.c	\
	ft_strnstr.c	\
	ft_isalnum.c	\
	ft_isprint.c	\
	ft_memmove.c	\
	ft_strlcpy.c	\
	ft_strrchr.c	\
	ft_isalpha.c	\
	ft_memchr.c		\
	ft_memset.c		\
	ft_strlen.c		\
	ft_tolower.c	\
	ft_calloc.c		\
	ft_strdup.c		\
	ft_substr.c		\
	ft_strtrim.c	\
	ft_split.c		\
	ft_itoa.c		\
	ft_strmapi.c	\
	ft_striteri.c	\
	ft_putchar_fd.c	\
	ft_putstr_fd.c	\
	ft_putendl_fd.c	\
	ft_putnbr_fd.c	\

SRCSB = ft_lstclear_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstnew_bonus.c\
	ft_lstmap_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstiter_bonus.c
	
OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

NAME = libft.a

C = cc

CFLAGS = -Werror -Wall -Wextra

RM = rm -f

LIBR = ar rcs

.c.o:
		${C} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${LIBR} ${NAME} ${OBJS}

bonus: ${OBJSB}
		${LIBR} ${NAME} ${OBJSB}

all: ${NAME}

clean:
		${RM} ${OBJS} ${OBJSB}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re