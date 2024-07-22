NAME := Violence

CC := c++

FLAGS := -Wall -Werror -Wextra

HEADER :=	HumanA.hpp\
			HumanB.hpp\
			Weapon.hpp\
	

SRC := 	HumanA.cpp\
		HumanB.cpp\
		Weapon.cpp\
		main.cpp\

OBJ =	$(SRC:%.cpp=obj/%.o)
		
all: $(NAME)
	
$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(OBJ) -o $@

obj/%.o:%.cpp $(HEADER)
	@mkdir -p obj
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re