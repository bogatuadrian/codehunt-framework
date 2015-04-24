
#include <vector>
#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork()
{
}

NeuralNetwork::NeuralNetwork(const std::vector<range> &in,
		const std::vector<range> &out) :
	in_domain(in), out_domain(out)
{

}


NeuralNetwork::NeuralNetwork(const NeuralNetwork &nn) :
	in_domain(nn.in_domain), out_domain(nn.out_domain)
{

}

std::vector<int> NeuralNetwork::input(const std::vector<int> &input)
{
	std::vector<int> res(input.size());
	return res;
}

void NeuralNetwork::output(const std::vector<int> &output)
{

}

