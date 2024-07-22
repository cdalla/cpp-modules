NAME := Animal

CC := c++

FLAGS := -Wall -Werror -Wextra

HEADER := Animal.hpp\
		  Dog.hpp\
		  Cat.hpp\
		  WrongAnimal.hpp\
		  WrongCat.hpp\

SRC := 	Animal.cpp\
		Dog.cpp\
		Cat.cpp\
		WrongAnimal.cpp\
		WrongCat.cpp\
		main.cpp\

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