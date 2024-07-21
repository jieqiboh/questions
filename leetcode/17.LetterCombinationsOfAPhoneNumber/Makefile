CC = clang
CFLAGS = -Wall -Wextra

all: main

clean:
	rm -f ./*.out

%.out: %.c
	$(CC) -o $@ $< $(CFLAGS)
