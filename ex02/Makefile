NAME = ex02
SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp
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

re: fclean all

frun: all
	@printf "\n========== START TEST ==========\n\n"
	./$(NAME)
	@printf "\n========== END TEST ==========\n"
	@$(MAKE) --no-print-directory fclean > /dev/null

.PHONY: all clean fclean re frun
