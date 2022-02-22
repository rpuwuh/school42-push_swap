NAME = push_swap

NAME_CHECKER = checker

OBJDIR=./obj/

HEADER = push_swap.h

SRC = ft_concatnstrschr.c ft_error.c ft_isdigitstrs.c ft_strsatoi.c\
	ft_issameints.c ft_intsnstrs.c ft_intsnumberedintsfree.c\
	ft_stacklst.c ft_pushswapinput.c ft_isstacksorted.c ft_initailize.c\
	ft_stradd.c ft_freenvp.c ft_sa.c ft_pa.c ft_ra.c ft_rra.c ft_sortthree.c\
	ft_isnotstrictlysorted.c ft_choosesort.c ft_differentscores.c\
	ft_score.c ft_chooseaction.c ft_advancedaction.c ft_middlesort.c 

SRC_B = ft_checker_utils.c

SRC_O = $(addprefix $(OBJDIR),$(SRC:.c=.o))

SRC_BO = $(addprefix $(OBJDIR),$(SRC_B:.c=.o))

LIBFT = $(addprefix $(OBJDIR),libft.a)

GNL = $(addprefix $(OBJDIR),get_next_line.a)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJDIR) $(LIBFT) $(OBJDIR)$(NAME).o $(SRC_O) $(HEADER) Makefile
	$(CC) $(CFLAGS) $(LIBFT) $(OBJDIR)$(NAME).o $(SRC_O)  -o $(NAME)

$(NAME_CHECKER): $(OBJDIR) $(LIBFT) $(GNL) $(OBJDIR)$(NAME_CHECKER).o $(SRC_O) $(SRC_BO) $(HEADER) Makefile
	$(CC) $(CFLAGS) $(LIBFT) $(GNL) $(SRC_O) $(SRC_BO) $(OBJDIR)$(NAME_CHECKER).o -o $(NAME_CHECKER)

$(OBJDIR):
	mkdir $(OBJDIR)

$(LIBFT): libft/*.c libft/*.h
	make -C ./libft/; cp ./libft/libft.a $(OBJDIR)libft.a; make fclean -C ./libft;

$(GNL): get_next_line/*.c get_next_line/*.h
	make -C ./get_next_line/; cp ./get_next_line/get_next_line.a $(OBJDIR)get_next_line.a;
	make fclean -C ./get_next_line;

$(OBJDIR)$(NAME).o: $(NAME).c $(HEADER) Makefile
	$(CC) $(CFLAGS)  -c -o $@ $<

$(OBJDIR)%.o: %.c $(NAME).c $(HEADER) Makefile
	$(CC) $(CFLAGS)  -c -o $@ $<

$(OBJDIR)$(NAME_CHECKER).o: $(NAME_CHECKER).c $(HEADER) Makefile
	$(CC) $(CFLAGS)  -c -o $@ $<

$(SRC_BO): $(SRC_B) ./checker.h
	$(CC) $(CFLAGS)  -c -o $@ $<

all: $(NAME) $(NAME_CHECKER)

exec: all clean

clean: 
	rm -f $(LIBFT) $(GNL) $(SRC_O) $(SRC_BO) $(OBJDIR)$(NAME).o $(OBJDIR)$(NAME_CHECKER).o

fclean: clean
	rm -f $(NAME) $(NAME_CHECKER); rm -rf $(OBJDIR)

re: fclean all

gimme: 
	echo "$(OBJDIR) $(LIBFT) $(OBJDIR)$(NAME).o $(SRC_O) $(HEADER) Makefile"

.PHONY: all clean fclean re exec gimme