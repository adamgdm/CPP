CC = c++
NAME = 
SRCS = 
OBJS = $(SRCS:.cpp=.o)
CXXFLAGS = -Wall -Werror -Wextra #-std=c++98 -fsanitize=address -g3

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re