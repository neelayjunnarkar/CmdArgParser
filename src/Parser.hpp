#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>

class Parser {
private:
	struct BoolArg {
		std::string lh; //long hand
		std::string sh; //short hand
		std::string desc = "";
		bool value = false; //should change to true if appears in command line arguments
	};
	struct PosArg {
		std::string id;
		int first;
		int count;
		std::string desc = "";
		std::vector<std::string> values = {};
	};
	struct LabeledArg {
		std::string lh;
		std::string sh;
		int count;
		bool req = false;
		std::string desc = "";
		std::vector<std::string> values = {};
		int first = -1; //position of lh or sh
	};
	std::vector<BoolArg> _bool_args;
	std::vector<PosArg> _pos_args;
	std::vector<LabeledArg> _labeled_args;
	std::vector<std::string> _raw_args;

	Parser(std::vector<std::string> args);
public:
	// Use for when data to parse taken directly, no alterations
	// Assumes that argv[0] is the executable
	// Ignores argv[0]
	static Parser from_env(int argc, char **argv);

	void set_positional(std::string internal_id, int first, int count, std::string desc);
	void set_bool(std::string lh, std::string sh, std::string desc);
	void set_labeled(std::string lh, std::string sh, int count, bool req, std::string desc);
	/*
	* Check if:
	* 	Arguments pass constraints
	*	All required arguments are there
	*/
	bool valid();

	void parse();
	
	bool get_bool(const std::string &name);
	std::vector<std::string> get_positional(const std::string &name);
	std::vector<std::string> get_labeled(const std::string &name);
	std::string get_as_string() const;
};

#endif
