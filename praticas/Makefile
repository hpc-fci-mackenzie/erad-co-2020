FLAGS = -Wall -fopenmp
bin = pratica1 pratica2 pratica3 pratica4 pratica5

all: $(bin)

$(bin):
	$(CC) $(FLAGS) $@.c -o $@

clean:
	rm $(bin)

.PHONY: all $(bin)
