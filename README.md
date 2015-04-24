# CodeHunt C++ Framework

## Description

A framework implemented in C++ based on the python test framework
for the 2nd homework of the ML course.

Implement your neural network in NeuralNetwork.h or derive the
NeuralNetwork class and implement its virtual methods.

## Dependencies

* make
* gnuplot
* gcc >= 4.7

## Usage

### Build

To build your project just run
```
make build
```

### Run

Running all the test with the next command
will also generate .png files representing the iteration-error plot for
each test.
```
make
```

You can also run a certain test with
```
./test <test_no>
```
or
```
make ARGS=<test_no>
```

### Clean

```
make clean-all
```
will also remove the .png files as opposed to
```
make clean
```

##

If you find anything wrong with this implementation please add an issue.
