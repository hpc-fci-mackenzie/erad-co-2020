FLAGS = -Wall -fopenmp
src = desafio1 desafio2 desafio3 desafio4 desafio5 desafio6
srcpp = desafio7

all: $(src) $(srcpp)

$(src):
	$(CC) $(FLAGS) $@.c -o $@

$(srcpp):
	$(CXX) $(FLAGS) $@.cpp -o $@

clean:
	rm $(src) $(srcpp)

.PHONY: all $(src) $(srcpp)
