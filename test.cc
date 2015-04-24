
#include <vector>
#include <utility>
#include <functional>
#include <string>
#include <random>
#include <climits>
#include <iostream>
#include <fstream>

#include "utils.h"

#include "test.h"
#include "NeuralNetwork.h"

/*
 * The test suite
 */
static const std::vector<Test> tests = {
		{
			{{-100, 100}},
			{{-100, 100}},
			[] (const std::vector<int> &in) -> std::vector<int> { return {-in[0]}; }
		},
		{
			{{-100, 100}, {-100, 100}},
			{{-300, 300}, {-200, 200}},
			[] (const std::vector<int> &in) -> std::vector<int> { auto x = in[0]; auto y = in[1]; return {x - 2 * y, x + y};}
		},
		{
			{{-100, 100}, {-100, 100}, {-100, 100}},
			{{-300, 300}, {-300, 300}, {-300, 300}},
			[] (const std::vector<int> &in) -> std::vector<int> { auto x = in[0]; auto y = in[1]; auto z = in[2]; return {x + y + z, y, z};}
		},
		{
			{{-20, 20}},
			{{400, 400}},
			[] (const std::vector<int> &in) -> std::vector<int> { auto x = in[0]; return {x * x};}
		}
	};

/*
 * run_test - Runs a given test and outputs the error corresponding to an iteration
 *
 * @test: the test to run
 * @out:  the ostream to write to (default writes to standard output)
 */
static int run_test(const Test &test, std::ostream &out = std::cout)
{
	std::random_device r;
	std::default_random_engine e(r());
	std::vector<unsigned long> times;
	std::vector<int> errors;

	NeuralNetwork nn(test.in_domain, test.out_domain);

	for (unsigned t = 0; t < iter; ++t) {
		times.push_back(t);
		std::vector<int> input;
		for (unsigned i = 0; i < test.in_domain.size(); ++i) {
			std::uniform_int_distribution<int> distribution(test.in_domain[i].first, test.in_domain[i].second);
			input.push_back(distribution(e));
		}

		auto output = test.f(input);
		auto o = nn.input(input);
		nn.output(output);

		int err = 0;
		if (output.size() != o.size()) {
			return -1;
		}
		else {
			for (unsigned i = 0; i < test.out_domain.size(); ++i) {
				int delta = o[i] - output[i];
				err += delta * delta;
			}
		}

		errors.push_back(err);
		out << t << " " << err << std::endl;
	}

	return 0;
}

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
		std::ofstream file("test" + std::to_string(i) + ".out");
		run_test(tests[i], file);
		file.close();
	}

	return 0;
}
