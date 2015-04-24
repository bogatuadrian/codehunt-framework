
#include <fstream>

#include "test.h"
#include "NeuralNetwork.h"

/*
 * usage: ./test [test_no]
 *
 * if no parameter given, it will run all the tests
 */
int main(int argc, char **argv)
{
	unsigned begin = 0, end = tests.size() - 1;

	if (argc > 1) {
		begin = std::stoi(std::string(argv[1]));
		end = begin;
	}

	for (unsigned i = begin; i <= end && i < tests.size(); ++i) {
		NeuralNetwork nn;
		std::ofstream file("test" + std::to_string(i) + ".out");
		run_test(nn, tests[i], file);
		file.close();
	}

	return 0;
}
