# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 15:39:03 by rponomar          #+#    #+#              #
#    Updated: 2025/05/05 22:08:02 by rponomar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fxp_2

ifeq ($(origin CXX), default)
CXX = c++
endif

ifeq ($(origin RM), default)
RM = rm -rf
endif

CXXSRC = \
	main.cpp		\
	Fixed.cpp
	
HDRS = \
	Fixed.hpp

CXXFLAGS ?= -O2
override CXXFLAGS += -std=c++98 -Wall -Wextra -Werror

override CPPFLAGS += -I.

.PHONY: all
all: $(NAME)

$(NAME): $(CXXSRC) $(HDRS) Makefile
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(CXXSRC) -o $@
	@echo "$(NAME): compiled"

.PHONY: clean
clean:

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME)

.PHONY: re
re: fclean all