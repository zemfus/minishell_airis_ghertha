READLINE			=	/Users/$(USER)/.brew/opt/readline
DIR_UTILS			=	0_utils/
DIR_SETUP			=	1_setup/
DIR_PARSE			=	2_parse/
DIR_EXEC			=	3_execute/
SRCS_UTILS			=	utils.c error/error.c \
						ft_utils/ft_double_strjoin.c ft_utils/ft_is.c ft_utils/ft_str_change.c \
						ft_utils/ft_strcjoin.c ft_utils/ft_strrdup.c ft_utils/ft_strstr.c \
						init/init_struct.c init/init_tool.c \
						free/free_lst.c free/free_struct.c  \
						struct/delete_env.c struct/make_struct.c struct/split_env.c 
SRCS_SETUP			=	signal/shell_signal.c signal/exec_signal.c \
						terminal/config.c terminal/cursor.c setup.c
SRCS_PARSE			=	redirection/heredoc.c redirection/redirect.c redirection/redirect_utils.c \
						analyze_command.c analyze_lexicon.c analyze_syntax.c analyze_token.c \
						analyze_utils.c lexer.c tokenizer.c parser.c parse_command.c parse_meta_char.c \
						parse_unclosed_pipe.c analyze_term_line.c
SRCS_EXEC			=	builtin/blt_cd.c builtin/blt_echo.c builtin/blt_env.c builtin/blt_exit.c \
						builtin/blt_export.c builtin/blt_pwd.c builtin/blt_unset.c builtin/blt_utils.c \
						builtin/init_blt.c builtin/print_env.c builtin/check_value.c \
						pipe/init_pipe.c pipe/run.c pipe/run_redir.c
SRCS_TMP			=	$(addprefix $(DIR_UTILS), $(SRCS_UTILS)) $(addprefix $(DIR_SETUP), $(SRCS_SETUP)) \
						$(addprefix $(DIR_PARSE), $(SRCS_PARSE)) $(addprefix $(DIR_EXEC), $(SRCS_EXEC)) main.c
SRCS				=	$(addprefix $(SRCS_DIR), $(SRCS_TMP))
OBJS				= 	$(SRCS:.c=.o)
DEPS				=	$(SRCS:.c=.d)
SRCS_DIR			=	./srcs/
OBJS_DIR			=	./objs/
INCS_DIR			=	./includes/

LIBFT				=	./libs/libft.a
LIBFT_DIR			=	./libs
LIBFT_INCS			=	./libs/includes/libft.h

CC					=	gcc
RM					=	rm -rf
CFLAGS				=	-Wall -Wextra -Werror -MMD
HEADER_FLAG			=	-I$(INCS_DIR) -I$(LIBFT_INCS) -I$(READLINE)/include
LIB_FLAG			= 	-L$(LIBFT_DIR) -lft -L$(READLINE)/lib -lreadline -lncurses
NAME				=	minishell

.c.o			:
					$(CC) $(CFLAGS) $(HEADER_FLAG) -c $< -o $@

all				:	$(NAME)

$(LIBFT)		:
					@make -C ./libs

$(NAME)			:	$(LIBFT) $(OBJS)
					$(CC) $(CFLAGS) $(LIB_FLAG) $(HEADER_FLAG) $(OBJS) -o $@

clean			:
					@make clean -C $(LIBFT_DIR)
					@$(RM) $(OBJS) 

fclean			:	clean
					@make fclean -C $(LIBFT_DIR)
					@$(RM) $(NAME)

re				:	fclean $(NAME)

-include $(DEPS)

.PHONY:			all clean fclean re
