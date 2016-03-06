#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <sstream>
#include <algorithm>

#include "MsgException.hpp"

struct Constraint {
	std::function<bool(std::vector<std::string>)> fn;
	Constraint(std::function<bool(std::vector<std::string>)> fn) : fn{fn} {};
	bool operator () (std::vector<std::string> input) const { return fn(input); }; 
};


struct IntRange : Constraint {
	IntRange(int in_min, int ex_max) :
		Constraint([=] (std::vector<std::string> input) -> bool {
			static int _in_min(in_min), _ex_max(ex_max);
			for (std::string str : input) {
				int num;
				std::istringstream(str) >> num;
				if (num >= _in_min && num < _ex_max)
					continue;
				throw MsgException(std::string("input out of range: ") + std::to_string(num));
			}
		}) {
	};
};

struct RealRange : Constraint {
	RealRange(double in_min, double ex_max) :
		Constraint([=] (std::vector<std::string> input) -> bool {
			static double _in_min(in_min), _ex_max(ex_max);
			for (std::string str : input) {
				double num;
				std::istringstream(str) >> num;
				if (num >= _in_min && num < _ex_max)
					continue;
				throw MsgException(std::string("input out of range: ") + std::to_string(num));
			}
		}) {
	};
};
