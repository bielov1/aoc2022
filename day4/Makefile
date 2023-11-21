CC = clang
CFLAGS = -Wall -Wextra -std=c11 -pedantic
INPUTS = sample.txt input.txt

.PHONY: test

test: 04 $(INPUTS)
	./04 $(INPUTS)

04: 04.c
	$(CC) $(CFLAGS) -o 04 04.c
