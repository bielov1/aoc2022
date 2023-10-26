CC = clang
CFLAGS = -Wall -Wextra -std=c11 -pedantic
INPUTS = sample.txt input.txt

.PHONY: test

test: 03 $(INPUTS)
	./03 $(INPUTS)

03: 03.c
	$(CC) $(CFLAGS) -o 03 03.c
