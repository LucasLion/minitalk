#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 19:41:05 by llion             #+#    #+#              #
#    Updated: 2023/01/14 14:34:32 by llion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= client.c	\
			  server.c
CFLAGS		= -Wall -Werror -Wextra
OBJS		= $(SRCS:.c=.o)
PRINTF		= ftprintf/libftprintf.a
CLIENT		= client
SERVER		= server
CC			= gcc


all:		$(PRINTF) $(CLIENT) $(SERVER)

$(PRINTF): 
			$(MAKE) -C ftprintf
			cp $(PRINTF) .

$(CLIENT):	$(PRINTF) $(OBJS) 
			$(CC) $(CFLAGS) client.c $(PRINTF) -o $(CLIENT)

$(SERVER):	$(PRINTF) $(OBJS) 
			$(CC) $(CFLAGS) server.c $(PRINTF) -o $(SERVER)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(CLIENT) $(SERVER)
			$(RM) libftprintf.a 
	
re:			fclean all

.PHONY:		clean re all fclean
 
