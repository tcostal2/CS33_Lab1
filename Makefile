CFLAGS = -Wall -Wextra -Wshadow -Wunreachable-code -Wredundant-decls  -Wmissing-declarations -Wold-style-definition \
-Wmissing-prototypes -Wdeclaration-after-statement \
-Wno-return-local-addr -Wunsafe-loop-optimizations -Wuninitialized -Werror -g3

CC = gcc 
PROGS = caesar xor

all: $(PROGS) 

caesar: caesar.o
	$(CC) $(CFLAGS) -o $@ $^

xor: xor.o
	$(CC) $(CFLAGS) -o $@ $^

caeasar.o: caesar.c
	$(CC) $(CFLAGS) -c $<

xor.o: xor.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(PROGS) *~ \#*
