NAME := Animale

CC := c++

FLAGS := -Wall -Werror -Wextra

HEADER := Animal.hpp\
		  Dog.hpp\
		  Cat.hpp\
		  Brain.hpp\

SRC := 	Animal.cpp\
		main.cpp\
		Dog.cpp\
		Cat.cpp\
		Brain.cpp

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