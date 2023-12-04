CC = cc
CFLAGS = -Wextra -Wall

SRC = src/main.c src/stack.c src/getch.c src/getop.c
EXEC = main

all:
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

clean:
	rm -rf $(EXEC)

run:
	./$(EXEC)
