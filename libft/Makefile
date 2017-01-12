NAME		= libft.a

SRCDIR		= .
OBJDIR		= objs
INCDIR		= includes

SRCNAM		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	  ft_putchar.c ft_putstr.c ft_strlen.c ft_memchr.c ft_memcmp.c ft_strdup.c \
	  ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
	  ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c \
	  ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	  ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c \
	  ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_isascii.c\
	  ft_isprint.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c\
	  ft_strsub.c ft_strndup.c ft_strjoin.c ft_strtrim.c ft_strsplit.c\
	  ft_itoa.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c\
	  ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c\
	  ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strtab.c\
	  ft_bzerocustom.c ft_setcustomtab.c ft_memadd.c
INCNAM		=

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -I$(INCDIR)

GIT			= README.md

SRC			= $(SRCNAM:%=$(SRCDIR)/%)
INC			= $(INCNAM:%=$(INCDIR)/%)
OBJ			= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	ranlib	$@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all git no printf check clean fclean re $(LIBFT)

git:
	git add $(SRC) $(INC) $(GIT)

no:
	@echo "Passage de la norminette :"
	@norminette $(SRC) $(INC)

printf:
	@echo "Detection des printf :\033[1;31m"
	@grep printf -r $(SRCDIR) $(INCDIR) | cat
	@printf "\033[0m"

check: no printf

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

# $(MAKE) needed so that the cleaning is done before starting to create again \
	# cf make -j 
re: fclean
	$(MAKE) all
