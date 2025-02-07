build:
	g++ -Wall \
		./src/implementations/gameStates/*.cpp \
		./src/implementations/buttons/Button.cpp \
		./src/main.cpp \
		-o game \
		-I/opt/homebrew/include/ -L/opt/homebrew/lib -lSDL2
run:
	./game
clean:
	rm game


execute:
	make build
	make run
	make clean