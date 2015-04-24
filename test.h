#ifndef TEST_H
#define  TEST_H
#include <vector>
#include <utility>
#include <iostream>

#include "utils.h"
#include "NeuralNetwork.h"

/*
 * The information needed for a test
 *
 * in_domain:  an array of intervals [min, max] corresponding to the input's range of values
 * out_domain: an array of intervals [min, max] corresponding to the output's range of values
 * f: the function to be aproximated
 */
struct Test {
	std::vector<range> in_domain;
	std::vector<range> out_domain;
	function f;
};

/*
 * The test suite
 */
const std::vector<Test> tests = {
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

const unsigned long iter = 100;
int run_test(NeuralNetwork &nn, const Test &test, std::ostream &out);
#endif
