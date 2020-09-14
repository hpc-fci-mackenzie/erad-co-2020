FLAGS = -Wall -fopenmp
bin = desafio1 desafio2

all: $(bin)

$(bin):
	$(CC) $(FLAGS) $@.c -o $@

clean:
	rm $(bin)

.PHONY: all $(bin)
