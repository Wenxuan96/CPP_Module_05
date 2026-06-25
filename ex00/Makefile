NAME = ex00
SRCS = main.cpp Bureaucrat.cpp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm $(NAME)

re:fclean all

.PHONY: all clean fclean re
