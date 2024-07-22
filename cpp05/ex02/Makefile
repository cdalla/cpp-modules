NAME := Bureaucrat

CC := c++

FLAGS := -Wall -Werror -Wextra

HEADER := Bureaucrat.hpp\
		  AForm.hpp\
		  ShrubberyCreationForm.hpp\
		  PresidentialPardonForm.hpp\
		  RobotomyRequestForm.hpp\

SRC := 	main.cpp\
		Bureaucrat.cpp\
		AForm.cpp\
		ShrubberyCreationForm.cpp\
		PresidentialPardonForm.cpp\
		RobotomyRequestForm.cpp\
		

OBJ =	$(SRC:%.cpp=obj/%.o)
		
all: $(NAME)
	
$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(OBJ) -o $@

obj/%.o:%.cpp $(HEADER)
	@mkdir -p obj
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -r obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re