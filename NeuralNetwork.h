#ifndef NEURAL_NET_H
#define NEURAL_NET_H
#include <vector>

#include "utils.h"

class NeuralNetwork {

private:
	std::vector<range> in_domain;
	std::vector<range> out_domain;
public:
	NeuralNetwork();
	NeuralNetwork(const std::vector<range> &in, const std::vector<range> &out);
	NeuralNetwork(const NeuralNetwork &nn);

	/* TODO: compute and return output */
	virtual std::vector<int> input(const std::vector<int> &input);
	/* TODO: update network w/ given output */
	virtual void output(const std::vector<int> &output);
};
#endif
