CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC = main.c
EXEC = out 

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

clean:
	rm -f $(EXEC)

run:
	./$(EXEC)
