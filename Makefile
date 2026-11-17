NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

OBJ_DIR = objects/
SRC_DIR = sources/
INC_DIR = includes/
LIBFT_DIR = $(INC_DIR)libft/
MACROLIBX_DIR = MacroLibX/
PARSER_DIR := parsing/

MACROLIBXDIR:= libs/MacroLibX/
MACROLIBX:=$(addprefix $(MACROLIBXDIR), libmlx.so)

SRC_FILES := main.c \
			 $(SRC_DIR)$(PARSER_DIR)gnl.c \
			 $(SRC_DIR)$(PARSER_DIR)parsing.c \
			 $(SRC_DIR)$(PARSER_DIR)error.c \
			 $(SRC_DIR)$(PARSER_DIR)info_file.c \
			 $(SRC_DIR)$(PARSER_DIR)map.c \

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_FILES))


all : $(OBJ_DIR).compiled $(NAME)

$(OBJ_DIR).compiled:
	@echo ""
	@printf "%s\n" '   /\\,/\\,                   ,,          ,, ,, '
	@printf "%s\n" "  /| || ||   '        '       ||          || || "
	@printf "%s\n" '  || || ||  \\ \\/\\ \\  _-_, ||/\\  _-_  || || '
	@printf "%s\n" '  ||=|= ||  || || || || ||_.  || || || \\ || || '
	@printf "%s\n" ' ~|| || ||  || || || ||  ~ || || || ||/   || || '
	@printf "%s\n" '  |, \\,\\, \\ \\ \\ \\ ,-_-  \\ |/ \\,/  \\ \\ '
	@printf "%s\n" ' _-                             _/              '
	@echo ""
	@echo ""

$(OBJ_DIR).running:
	@mkdir -p $(OBJ_DIR)
	@touch $(OBJ_DIR).running
	@echo ""
	@printf "%s\n" '   /\\,/\\,                   ,,          ,, ,, '
	@printf "%s\n" "  /| || ||   '        '       ||          || || "
	@printf "%s\n" '  || || ||  \\ \\/\\ \\  _-_, ||/\\  _-_  || || '
	@printf "%s\n" '  ||=|= ||  || || || || ||_.  || || || \\ || || '
	@printf "%s\n" ' ~|| || ||  || || || ||  ~ || || || ||/   || || '
	@printf "%s\n" '  |, \\,\\, \\ \\ \\ \\ ,-_-  \\ |/ \\,/  \\ \\ '
	@printf "%s\n" ' _-                             _/              '
	@echo ""
	@echo ""

$(NAME) : $(OBJ) $(LIBFT)
	@touch $(OBJ_DIR).compiled
	@echo "𖤐⭒๋࣭ ⭑ Compilation of Minishell finished !"
	@${CC} ${CFLAGS} -I ${INC_DIR} -o ${NAME} ${OBJ} ${LIBFT}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -I $(INC_DIR) -c $< -o $@

$(LIBFT) :
	@echo "𖤐⭒๋࣭ ⭑ Compilation of libft finished !"
	@make --no-print-directory -C $(LIBFT_DIR)

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

clean : $(OBJ_DIR).running
	@echo "👉🗑️ Cleaning all .o files !"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

fclean : $(OBJ_DIR).running clean
	@echo "💥 Deleting Minishell"
	@rm -rf $(NAME)
	@echo "💥 Deleting Libft"
	@rm -rf $(LIBFT)

re : $(OBJ_DIR).running fclean $(NAME)
	@rm -f $(OBJ_DIR).running

.PHONY : all clean fclean re
