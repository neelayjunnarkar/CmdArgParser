#include "Parser.hpp"


Parser::Parser(int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		_raw_args.push_back(std::string{argv[i]});
	}
}

void Parser::add_arg(std::string longhand, std::vector<Constraint> constraints, std::string shorthand, std::string description) {

}

bool Parser::check_validity(std::string *const err_msg) {
	return true;
}

std::string Parser::get_raw() const {
	std::string list = _raw_args[0];

	for (int i = 1; i < _raw_args.size(); ++i) {
		list += std::string{" "} + _raw_args[i];
	}
	return list;
}
