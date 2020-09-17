FLAGS = -Wall -fopenmp
bin = pratica1 pratica2 pratica3 pratica4 pratica5 pratica6 pratica7

all: $(bin)

$(bin):
	$(CC) $(FLAGS) $@.c -o $@

clean:
	rm $(bin)

.PHONY: all $(bin)
