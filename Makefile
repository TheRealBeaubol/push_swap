# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 13:00:22 by lboiteux          #+#    #+#              #
#    Updated: 2024/03/25 16:00:47 by lboiteux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# 								NAME PROJECT								   #
# **************************************************************************** #

NAME				=	push_swap

# **************************************************************************** #
# 								  COMMANDS									   #
# **************************************************************************** #

CC					=	@clang
CFLAGS				=	-Wall -Wextra -Werror
IFLAGS_MANDATORY	=	-I ./mandatory/includes -I ./libft/includes
IFLAGS_BONUS		=	-I ./mandatory/includes -I ./bonus/includes -I ./libft/includes
MK					=	@mkdir -p
CPT_BONUS			=	$(shell ls -lR bonus/srcs/ | grep -F .c | wc -l)
CPT_MANDATORY		=	$(shell ls -lR mandatory/srcs/ | grep -F .c | wc -l)
FILE_MANDATORY		=	$(shell echo "$(CPT_MANDATORY)" | bc)
FILE_BONUS			=	$(shell echo "$(CPT_BONUS) + $(CPT_MANDATORY) - 1" | bc)
PROJ_CMP_BONUS	=	1
PROJ_CMP_MANDATORY	=	1
RM					= 	@rm -rf
BONUS				=	checker

LIBFT_DIR			=	./libft
LIBFT_NAME			=	libft.a
LIBFT_PATH			= 	$(LIBFT_DIR)/$(LIBFT_NAME)

# **************************************************************************** #
#                                   COLORS                                     #
# **************************************************************************** #
COLOR_1	= \033[1;38;5;28m
COLOR_2	= \033[1;38;5;120m
COLOR_3	= \033[1;38;5;240m
COLOR_4	= \033[1;38;5;255m
COLOR_5	= \033[1;38;5;248m
RESET	= \033[0m

# **************************************************************************** #
# 								   SOURCES									   #
# **************************************************************************** #

#SOURCES
SRCS_1	= 	mandatory/srcs/main.c \

SRCS_2	=	mandatory/srcs/utils.c \
			mandatory/srcs/make_list.c \
			mandatory/srcs/check.c \
			mandatory/srcs/choose_rotate.c \
			mandatory/srcs/cost_to_a.c \
			mandatory/srcs/cost_to_b.c \
			mandatory/srcs/do_and_push_a.c \
			mandatory/srcs/do_and_push_b.c \
			mandatory/srcs/instructions_utils.c \
			mandatory/srcs/push_swap.c \
			mandatory/srcs/search_index.c \
			mandatory/srcs/push.c \
			mandatory/srcs/reverse_rotate.c \
			mandatory/srcs/rotate.c \
			mandatory/srcs/swap.c \

#BONUSES SOURCES
SRCS_BONUSES = 	bonus/srcs/main.c \

# OBJECTS

SRCS_OBJS_1  =  $(SRCS_2) $(SRCS_1)
SRCS_OBJS_2  = $(SRCS_BONUSES) $(SRCS_2)
OBJS_DIR_1	:=	.objs_mandatory
OBJS_DIR_2	:=	.objs_bonus
OBJS_1		:=	$(addprefix $(OBJS_DIR_1)/, $(SRCS_OBJS_1:%.c=%.o))
OBJS_2		:=	$(addprefix $(OBJS_DIR_2)/, $(SRCS_OBJS_2:%.c=%.o))

$(LIBFT_PATH):
		@printf "  📖 $(COLOR_3)Compiling $(LIBFT_NAME)$(RESET) 📖\n"
		@make -C $(LIBFT_DIR) -j --no-print-directory
		@printf "  🖥️  $(COLOR_3)Compiling $(NAME) $(RESET) 🖥️\n"

$(OBJS_DIR_1)/%.o: %.c
	$(MK) $(@D)
	$(CC) $(CFLAGS) $(IFLAGS_MANDATORY) -c $< -o $@
	@if [ "$(PROJ_CMP_MANDATORY)" -ne "$(FILE_MANDATORY)" ]; then \
		printf " $(COLOR_1) [$(RESET)$(PROJ_CMP_MANDATORY)$(COLOR_1)/$(RESET)$(FILE_MANDATORY)$(COLOR_1)]\t$(RESET)$<                     \r"; \
	else \
		printf " $(COLOR_1) [$(RESET)$(PROJ_CMP_MANDATORY)$(COLOR_1)/$(RESET)$(FILE_MANDATORY)$(COLOR_1)]\t$(RESET)$<                 \n\n"; \
	fi
	@$(eval PROJ_CMP_MANDATORY=$(shell echo $$(($(PROJ_CMP_MANDATORY)+1))))

$(OBJS_DIR_2)/%.o: %.c
	$(MK) $(@D)
	$(CC) $(CFLAGS) $(IFLAGS_BONUS) -c $< -o $@
	@if [ "$(PROJ_CMP_BONUS)" -ne "$(FILE_BONUS)" ]; then \
		printf " $(COLOR_1) [$(RESET)$(PROJ_CMP_BONUS)$(COLOR_1)/$(RESET)$(FILE_BONUS)$(COLOR_1)]\t$(RESET)$<                     \r"; \
	else \
		printf " $(COLOR_1) [$(RESET)$(PROJ_CMP_BONUS)$(COLOR_1)/$(RESET)$(FILE_BONUS)$(COLOR_1)]\t$(RESET)$<                 \n\n"; \
	fi
	@$(eval PROJ_CMP_BONUS=$(shell echo $$(($(PROJ_CMP_BONUS)+1))))

$(NAME): $(OBJS_1) $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS_1) $(LIBFT_PATH) -o $(NAME)
	@printf "  ✅ $(COLOR_2)$(NAME) successfully compiled$(RESET)\n"
	@printf "  🔄 $(COLOR_3)$(NAME) is ready to run$(RESET) \n\n"
	
$(BONUS): $(OBJS_2) $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS_2) $(LIBFT_PATH) -o $(BONUS)
	@printf "  ✅ $(COLOR_2)$(BONUS) successfully compiled$(RESET)\n"
	@printf "  🔄 $(COLOR_3)$(BONUS) is ready to run$(RESET) \n\n"

bonus: $(LIBFT_PATH) $(BONUS)

all: $(LIBFT_PATH) $(NAME) 

clean:
	@printf "  👾 \033[1;4;38;5;240m$(NAME)$(RESET)   \n  $(COLOR_3)└──> 🗑️    \033[1;38;5;255m.o \033[1;38;5;248mhave been deleted$(RESET)\n"	
	$(RM) $(OBJS_DIR_1) $(OBJS_DIR_2)

fclean: clean
	$(RM) $(NAME) $(BONUS)
	@printf "  $(COLOR_3)└──> 🗑️    \033[1;38;5;255m$(NAME) binary \033[1;38;5;248mhas been deleted$(RESET)\n\n"
	@make fclean -C $(LIBFT_DIR) --no-print-directory -j

re:	fclean all

.PHONY:	re fclean all clean bonus