CC=gcc

totient: TotientRange.c
	$(CC) -o totient TotientRange.c

test: totient
	./totient 0 100
	./totient 0 1000
	./totient 5 3000
	./totient 100 10000

.PHONY: clean

clean:
	rm totient
