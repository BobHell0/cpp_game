build:
	g++ -Wall ./src/*.cpp -o game -I/opt/homebrew/include/ -L/opt/homebrew/lib -lSDL2
run:
	./game
clean:
	rm game


execute:
	make build
	make run