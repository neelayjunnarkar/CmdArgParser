#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <sstream>
#include <algorithm>

#include "Constraints.hpp"

class Parser {
public:
	Parser(int argc, char **argv);

	/*
	 * Check if:
	 * 	Arguments pass constraints
	 *	All required arguments are there
	 */
	bool check_validity();

	void parse();

	std::string get_raw() const;
private:
	std::vector<std::string> _raw_args;
};
