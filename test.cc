
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
#include "MyNeuralNetwork.h"

/*
 * run_test - Runs a given test and outputs the error corresponding to an iteration
 *
 * @test: the test to run
 * @out:  the ostream to write to (default writes to standard output)
 */
int run_test(NeuralNetwork &nn, const Test &test, std::ostream &out = std::cout)
{
	std::random_device r;
	std::default_random_engine e(r());
	std::vector<unsigned long> times;
	std::vector<int> errors;

	nn = NeuralNetwork(test.in_domain, test.out_domain);

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
