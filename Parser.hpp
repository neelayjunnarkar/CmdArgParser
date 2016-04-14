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
    	const int lh = 0; // if name.size == 2
    	const int sh = 1; // if name.size() == 2
    	const int internal_id = 0; // if name.size() == 1
		std::vector<std::string> name;
		std::string desc;
		_Arg(const std::vector<std::string> &name, const std::string &desc);
		std::vector<std::string> args;
	};
	template <typename T>
	struct Arg : _Arg {
		std::vector<int> *poss;
		std::vector<Constraint> *cstrts;
		bool *req;
		Arg(std::string internal_id, std::vector<int> poss, std::vector<Constraint> cstrts, bool req, std::string desc);
		Arg(std::string lh, std::string sh, std::string desc);
		Arg(std::string lh, std::string sh, std::vector<Constraint> cstrts, bool req, std::string desc);
		std::vector<T> arg_vals;
	};

	std::vector<std::string> _raw_args;
	std::vector<_Arg*> _args;
public:
	Parser(int argc, char **argv);

	void set_positional(std::string internal_id, std::vector<int> poss, std::vector<Constraint> cstrts, bool req, std::string desc) const;
	void set_bool(std::string lh, std::string sh, std::string desc) const;
	void set_labeled(std::string lh, std::string sh, std::vector<Constraint> cstrts, bool req, std::string desc) const;
	/*
	* Check if:
	* 	Arguments pass constraints
	*	All required arguments are there
	*/
	bool valid() const;

	void parse();

	std::string get_raw() const;
};

#endif