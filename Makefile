NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

VPATH = sources/cub:sources/parsing
INC_DIR = includes/
INC_MACROLIBXDIR = libs/MacroLibX/includes/
INC_LIBFTDIR = libs/Libft
OBJ_DIR = objects/

MACROLIBXDIR:= libs/MacroLibX/
LIBFTDIR:= libs/Libft/
MACROLIBX:=$(addprefix $(MACROLIBXDIR), libmlx.so)
LIBFT:=$(addprefix $(LIBFTDIR), libft.a)

SRC_FILES := game.c hook.c map.c player.c rayCasting.c texture.c utils.c error.c gnl.c info_file.c map_parsing.c parsing.c main.c ft_split_set.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

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

$(NAME) : $(OBJ) $(LIBFT) $(MACROLIBX)
	@touch $(OBJ_DIR).compiled
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lm -lSDL2 $(LIBFT) $(MACROLIBX)
	@echo "𖤐⭒๋࣭ ⭑ Compilation of Minishell finished !"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I$(INC_MACROLIBXDIR) -I$(LIBFTDIR) -c $< -o $@

$(LIBFT) :
	@make -sC $(LIBFTDIR)
	@echo "𖤐⭒๋࣭ ⭑ Compilation of libft finished !"

$(MACROLIBX) :
	@make -sC $(MACROLIBXDIR) -j
	@echo "𖤐⭒๋࣭ ⭑ Compilation of MacroLibX finished !"

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

clean : $(OBJ_DIR).running
	@echo "👉🗑️ Cleaning all .o files !"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -sC $(LIBFTDIR) clean
	@$(MAKE) -sC $(MACROLIBXDIR) clean

fclean : $(OBJ_DIR).running clean
	@echo "💥 Deleting Minishell"
	@rm -rf $(NAME)
	@$(MAKE) -sC $(LIBFTDIR) fclean
	@$(MAKE) -sC $(MACROLIBXDIR) fclean
	@echo "💥 Deleting Libft"

re : $(OBJ_DIR).running fclean $(NAME)
	@rm -f $(OBJ_DIR).running

.PHONY : all clean fclean re
