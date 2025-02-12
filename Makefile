build:
	g++ -Wall -std=c++1y -g \
		-fsanitize=address \
		./src/implementations/gameStates/*.cpp \
		./src/implementations/buttons/Button.cpp \
		./src/implementations/*.cpp \
		./src/implementations/collisionStrategy/*.cpp \
		./src/GameContext.cpp \
		./src/main.cpp \
		-o game \
		-I/opt/homebrew/include/ -L/opt/homebrew/lib -lSDL2
run:
	./game
clean:
	rm game
	rm -r game.dSYM


execute:
	make build
	make run
	make clean