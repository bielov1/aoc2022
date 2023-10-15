CFLAGS = -Wall -Wextra -std=c11 -pedantic

.PHONY: test
test: main run

main: main.c
	$(CC) $(CFLAGS) -o main main.c

run: main
	./main
