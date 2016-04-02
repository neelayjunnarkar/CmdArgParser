#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <sstream>
#include <algorithm>
#include <array>
#include <exception>

#include "Constraint.hpp"

class Parser {
private:
	struct _Arg {
		std::string name;
		std::string desc;
		_Arg(const std::string &name, const std::string &desc) :
			name{name},
			desc{desc} { 
		}
		std::vector<std::string> args;
	};
	template <typename T>
	struct Arg : _Arg {
		
	}
	
	std::vector<std::string> _raw_args;
public:
	Parser(int argc, char **argv);

	void set_positional(std::vector<int> poss, std::vector<Constraint> cstrts, bool req, std::string desc) const;
	void set_bool(std::string lh, std::string sh, std::string desc) const;
	void set_labeled(std::string lh, std::string sh, std::vector<Constraint> cstrts, bool req, std::string desc) const;
	/*
	 * Check if:
	 * 	Arguments pass constraints
	 *	All required arguments are there
	 */
	bool check_validity() const;

	void parse();

	std::string get_raw() const;
};

#endif