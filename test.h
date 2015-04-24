#ifndef TEST_H
#define  TEST_H
#include <vector>
#include <utility>
#include <iostream>

#include "utils.h"

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

static const unsigned long iter = 100;
static int run_test(const Test &test, std::ostream &out);
#endif
