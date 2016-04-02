#include "Parser.hpp"

Parser::Parser(int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		_raw_args.push_back(std::string{argv[i]});
	}
}

bool Parser::check_validity() const {

	return true;
}

void Parser::parse() {

}

std::string Parser::get_raw() const {
	if (_raw_args.size() == 0)
		return "";
    
	std::string list = _raw_args[0];

	for (int i = 1; i < _raw_args.size(); ++i) {
		list += std::string{" "} + _raw_args[i];
	}
	return list;
}
