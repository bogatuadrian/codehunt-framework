
CC=g++
CCFLAGS=-Wall -O3 -std=c++11
EXEC=test
OBJ=test.o NeuralNetwork.o main.o


run: build
	./$(EXEC) $(ARGS)
	./plot.sh
	rm -f *.out

build: $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(EXEC)

test.o: test.cc
	$(CC) -c $(CCFLAGS) test.cc -o test.o

main.o: main.cc
	$(CC) -c $(CCFLAGS) main.cc -o main.o

NeuralNetwork.o: NeuralNetwork.cc
	$(CC) -c $(CCFLAGS) NeuralNetwork.cc -o NeuralNetwork.o

clean:
	rm -f $(OBJ)
	rm -f $(EXEC)
	rm -f *.out

clean-all: clean
	rm -f *.png


