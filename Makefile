NAME		= philo
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -g
CPPFLAGS	= -Iinclude -Ilibft
LDFLAGS		= -Llibft
LINKS		= -lft -lm -lpthread
RM			= rm -f
MAKEFLAGS   := --no-print-directory

LIBFT		= libft/libft.a

SRC_DIR		= src
OBJ_DIR		= .dir
SRCS		:= main.c \
				ft_utils.c \
				ft_philo_routine.c \
				ft_monitor.c \
				ft_menage_fork.c \
				ft_init_thread.c \
				ft_init_table.c \
				ft_error.c \

OBJS		:= $(SRCS:.c=.o)
OBJS		:= $(addprefix $(OBJ_DIR)/, $(OBJS))

all: $(NAME)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@[ -f $(LIBFT) ] || make -C libft/
	$(info ${BOLD}Creating  -> ${YELLOW}libft.a${NO_COLOR})
	$(CC) $(OBJS) $(LDFLAGS) $(CFLAGS) $(LINKS) -o $(NAME)
	echo "${BOLD}Creating  -> ${RED}$(NAME)${NO_COLOR}"
	${MAKE} goku


clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	make clean -C libft/
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
.SILENT:

RED			:= ${shell tput setaf 1}
BLUE		:= ${shell tput setaf 4}
YELLOW		:= ${shell tput setaf 3}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

goku:
	@echo '⣿⣿⠿⠿⠿⠿⣿⣷⣂⠄⠄⠄⠄⠄⠄⠈⢷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿'
	@echo '⣷⡾⠯⠉⠉⠉⠉⠚⠑⠄⡀⠄⠄⠄⠄⠄⠈⠻⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿'
	@echo '⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⡀⠄⠄⠄⠄⠄⠄⠄⠄⠉⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿'
	@echo '⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⠎⠄⠄⣀⡀⠄⠄⠄⠄⠄⠄⠄⠘⠋⠉⠉⠉⠉⠭⠿⣿'
	@echo '⡀⠄⠄⠄⠄⠄⠄⠄⠄⡇⠄⣠⣾⣳⠁⠄⠄⢺⡆⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄'
	@echo '⣿⣷⡦⠄⠄⠄⠄⠄⢠⠃⢰⣿⣯⣿⡁⢔⡒⣶⣯⡄⢀⢄⡄⠄⠄⠄⠄⠄⣀⣤⣶'
	@echo '⠓⠄⠄⠄⠄⠄⠸⠄⢀⣤⢘⣿⣿⣷⣷⣿⠛⣾⣿⣿⣆⠾⣷⠄⠄⠄⠄⢀⣀⣼⣿'
	@echo '⠄⠄⠄⠄⠄⠄⠄⠑⢘⣿⢰⡟⣿⣿⣷⣫⣭⣿⣾⣿⣿⣴⠏⠄⠄⢀⣺⣿⣿⣿⣿'
	@echo '⣿⣿⣿⣿⣷⠶⠄⠄⠄⠹⣮⣹⡘⠛⠿⣫⣾⣿⣿⣿⡇⠑⢤⣶⣿⣿⣿⣿⣿⣿⣿'
	@echo '⣿⣿⣿⣯⣤⣤⣤⣤⣀⣀⡹⣿⣿⣷⣯⣽⣿⣿⡿⣋⣴⡀⠈⣿⣿⣿⣿⣿⣿⣿⣿'
	@echo '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣝⡻⢿⣿⡿⠋⡒⣾⣿⣧⢰⢿⣿⣿⣿⣿⣿⣿⣿'
	@echo '⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⣏⣟⣼⢋⡾⣿⣿⣿⣘⣔⠙⠿⠿⠿⣿⣿⣿'
	@echo '⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⣛⡵⣻⠿⠟⠁⠛⠰⠿⢿⠿⡛⠉⠄⠄⢀⠄⠉⠉⢉'
	@echo '⣿⣿⣿⣿⡿⢟⠩⠉⣠⣴⣶⢆⣴⡶⠿⠟⠛⠋⠉⠩⠄⠉⢀⠠⠂⠈⠄⠐⠄⠄⠄'