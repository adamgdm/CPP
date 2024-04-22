CC = c++
NAME = btc
SRCS = main.cpp BitcoinExchange.cpp
HDRS = BitcoinExchange.hpp
OBJS = $(SRCS:.cpp=.o)
CXXFLAGS = -Wall -Werror -Wextra #-std=c++98

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re