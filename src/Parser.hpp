#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>

class Parser {
private:
	struct BoolArg {
		std::string lh; //long hand
		std::string sh; //short hand
		bool value = false; //should change to true if appears in command line arguments
		std::string desc = "";
	};
	std::vector<BoolArg> _bool_args;
	std::vector<std::string> _raw_args;
public:
	Parser(int argc, char **argv);

	void set_positional(std::string internal_id, std::vector<int> poss, bool req, std::string desc);
	void set_bool(std::string lh, std::string sh, std::string desc);
	void set_labeled(std::string lh, std::string sh, bool req, std::string desc);
	/*
	* Check if:
	* 	Arguments pass constraints
	*	All required arguments are there
	*/
	bool valid() const;

	void parse();
	
	bool get_bool(const std::string &name);
	std::string get_as_string() const;
};

#endif
