CC = gcc

all:
	$(CC) ./src/*.c -I ./inc/ -o app

run:
	./app

clean:
	rm *.exe
