RED			=	\033[38;5;160m
RED_B		=	\033[48;5;160m
DELETED		=	\033[48;5;160m[DELETED]\033[0m
GREEN		=	\033[38;5;40m
GREEN_B		=	\033[48;5;40m
COMPILATION	=	\033[48;5;40m[COMPILATION]\033[0m $(GREEN)
BLUE		=	\033[38;5;123m
BLUE_B		=	\033[48;5;39m
INFO		=	\033[48;5;39m[INFORMATION]\033[0m $(BLUE)
RESET		=	\033[0m
ifeq ($(shell uname), Linux)
	OS			=	Linux
	PROGRESS_DONE_CHAR = \#
	PROGRESS_TODO_CHAR = -
else
	OS				=	Mac
	PROGRESS_DONE_CHAR = 🟩
	PROGRESS_TODO_CHAR = ⬜️
endif
PROGRESS_WIDTH = 20
CURRENT_PROGRESS = 0
TOTAL_PROGRESS = $(words $(OBJ))

NAME		=	minishell
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
#-fsanitize=address

LIBFT_DIR	=	./inc/42-libft/
LIBFT		=	$(LIBFT_DIR)libft.a
HDRS_DIR	=	./inc/
SRC_DIR		=	./src
OBJ_DIR		=	./obj

SRC			=	$(wildcard $(SRC_DIR)/*.c) #! REMOVE LATER
HDRS 		=	-I$(LIBFT_DIR)inc -I$(HDRS_DIR)  -I /usr/local/Cellar/readline/8.1.1/include/
LIBS		=	-L$(LIBFT_DIR) -L /usr/local/Cellar/readline/8.1.1/lib/
# OBJ         = 	$(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
OBJ			=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))


all: libft ascii-art $(NAME)

$(NAME): $(OBJ)
	@echo
	@echo "$(COMPILATION)Program \"$(NAME)\" compilation:"
	$(CC) $(CFLAGS) $(LIBS) $(HDRS) $(OBJ) -o $(NAME) $(LIBFT) -lreadline
	@echo "$(RESET)$(INFO)$@ executable has been created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(HDRS) -c $^ -o $@
	$(eval CURRENT_PROGRESS=$(shell echo $$(($(CURRENT_PROGRESS)+1))))
	$(eval PERCENTAGE=$(shell echo $$(($(CURRENT_PROGRESS)*100/$(TOTAL_PROGRESS)))))
	@if [ $(CURRENT_PROGRESS) -eq $(TOTAL_PROGRESS) ]; then \
		printf "\r$(GREEN_B)[COMPILATION]$(RESET) \033[38;5;40m$(PERCENTAGE)%% [$$(printf '%*s' $$(($(CURRENT_PROGRESS)*$(PROGRESS_WIDTH)/$(TOTAL_PROGRESS))) | tr ' ' '$(PROGRESS_DONE_CHAR)')$$(printf '%*s' $$(($(PROGRESS_WIDTH)-($(CURRENT_PROGRESS)*$(PROGRESS_WIDTH)/$(TOTAL_PROGRESS)))) | tr ' ' '$(PROGRESS_TODO_CHAR)')] $<\033[0m ✅                   $(RESET)\n"; \
	else \
		printf "\r$(GREEN_B)[COMPILATION]$(RESET) \033[38;5;51m$(PERCENTAGE)%% [$$(printf '%*s' $$(($(CURRENT_PROGRESS)*$(PROGRESS_WIDTH)/$(TOTAL_PROGRESS))) | tr ' ' '$(PROGRESS_DONE_CHAR)')$$(printf '%*s' $$(($(PROGRESS_WIDTH)-($(CURRENT_PROGRESS)*$(PROGRESS_WIDTH)/$(TOTAL_PROGRESS)))) | tr ' ' '$(PROGRESS_TODO_CHAR)')] $<$(RESET)"; \
	fi
	@sleep 0.01


libft:
	@make all --quiet -C  $(LIBFT_DIR)
	@clear

clean:
	@make clean --quiet -C $(LIBFT_DIR)
	@for obj in $(OBJ); do \
		rm -f $$obj; \
		printf "$(RED_B)[DELETED]$(RESET) $(RED)$$obj$(RESET)\n"; \
	done

fclean: clean
	@make fclean --quiet -C $(LIBFT_DIR)
	@rm -f $(NAME);
	@printf "$(RED_B)[DELETED]$(RESET) $(RED)$(NAME)$(RESET)\n"; \

fclean_fast:
	@for obj in $(OBJ); do \
		rm -f $$obj; \
		printf "$(RED_B)[DELETED]$(RESET) $(RED)$$obj$(RESET)\n"; \
	done
	@rm -f $(NAME);
	@printf "$(RED_B)[DELETED]$(RESET) $(RED)$(NAME)$(RESET)\n"; \

re: fclean all

sre: fclean_fast all

norm:
	@norminette * | grep Error

git:
	@echo "$(BLUE)"
	git add *
	@read -p "Commit msg:" msg;\
	git commit -m "$$msg"
	git push
	@echo "$(INFO)$(GREEN)Git add, commit, push performed ✅$(RESET)"

ascii-art:
	@echo "\033[1m\033[38;5;231m        _.-''|''-._                                \033[0m"
	@echo "\033[1m\033[38;5;231m    .-'     |     \`-.                       \033[0m"
	@echo "\033[1m\033[38;5;231m  .'\       |     _____ ________              _____  .__       .__  _________.__           .__  .__    \033[0m"
	@echo "\033[1m\033[38;5;231m.'   \      |    /  |  |\_____  \            /     \ |__| ____ |__|/   _____/|  |__   ____ |  | |  |   \033[0m"
	@echo "\033[1m\033[38;5;195m\     \     |   /   |  |_/  ____/   ______  /  \ /  \|  |/    \|  |\_____  \ |  |  \_/ __ \|  | |  |   \033[0m"
	@echo "\033[1m\033[38;5;159m \`\    \    |  /    ^   /       \  /_____/ /    Y    \  |   |  \  |/        \|   Y  \  ___/|  |_|  |__ \033[0m"
	@echo "\033[1m\033[38;5;123m   \`\   \   |  \____   |\_______ \         \____|__  /__|___|  /__/_______  /|___|  /\___  >____/____/ \033[0m"
	@echo "\033[1m\033[38;5;123m     \`\  \  |  /    |__|        \/                 \/        \/           \/      \/     \/            \033[0m"
	@echo "\033[3m\033[38;5;123m    _.-\`\ \ | / /'-._                                             made with ♥ by @kgebski & @cjackows\033[0m"
	@echo "\033[3m\033[38;5;123m   {_____\`\ | /'_____}                    \033[38;5;123m                                                \033[0m"
	@echo "\033[3m\033[38;5;123m           \`-'            \033[38;5;123m                                                                               \033[0m"
	@echo


.PHONY: all clean fclean re sre git libft
