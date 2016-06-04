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
		const int lh = 0; // long hand. if name.size == 2
    		const int sh = 1; // short hand. if name.size() == 2
    		const int internal_id = 0; // if name.size() == 1
		std::vector<std::string> name;
		std::string desc;
		std::vector<std::string> args;
		_Arg(const std::vector<std::string> &name, const std::string &desc);
	};
	template <typename T>
	struct Arg : _Arg {
		std::vector<int> *poss; // For Positional, defines indices of values, where <exe> is index 0
		std::vector<Constraint> *cstrts; // For all, but not necessary
		bool *req; // for Positional and Labeled arguments
		int *count; //for Labeled arguments, parser will check for count number of values after the label
		/*
		 * Positional: arguments have no label, and must be at certain indices where <exe> is index 0
		 */
		Arg(std::string internal_id, std::vector<int> poss, std::vector<Constraint> cstrts, bool req, std::string desc);
		/*
		 * Bool: optional arguments 
		 * eg. "-std=c++14" for g++
		 */
		Arg(std::string lh, std::string sh, std::string desc);
		/*
		 * Labeled: arguments like positional, but not tied to certain indices; values follow label instead
		 */
		Arg(std::string lh, std::string sh, int count, std::vector<Constraint> cstrts, bool req, std::string desc);
		std::vector<T> arg_vals; // Values for this argument in particular
		enum class Type {
			ERROR	   = 0b000,
			POSITIONAL = 0b001,
			BOOL	   = 0b010,
			LABELED    = 0b100	
		} type;
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
