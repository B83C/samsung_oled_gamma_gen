SRC = $(wildcard *.c)

main: $(SRC)
	gcc -o main $(SRC) -I  ./
