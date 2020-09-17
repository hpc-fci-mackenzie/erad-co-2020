FLAGS = -Wall -fopenmp
bin = desafio1 desafio2 desafio3 desafio4 desafio5 desafio6

all: $(bin)

$(bin):
	$(CC) $(FLAGS) $@.c -o $@

clean:
	rm $(bin)

.PHONY: all $(bin)
