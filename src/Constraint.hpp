#ifndef CONSTRAINT_HPP
#define CONSTRAINT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <sstream>

#include "MsgException.hpp"

struct Constraint {
	std::function<bool(std::vector<std::string>)> fn;
	Constraint(std::function<bool(std::vector<std::string>)> fn) : fn{fn} {};
	bool operator () (std::vector<std::string> input) const { return fn(input); }; 
};

template <typename T>
struct Range : Constraint {
	Range(T min, T max) :
		Constraint([=] (const std::vector<std::string> &input) -> bool {
			static T _min(min);
			static T _max(max);
			for (const std::string &arg : input) {
				T num;
				std::istringstream(arg) >> num;
				if (num >= _min && num <= _max)
					continue;
				return false;
			}				
		}) {
	}
};

#endif