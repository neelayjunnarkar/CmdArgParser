#include "Parser.hpp"


Parser::Parser(int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		_raw_args.push_back(std::string{argv[i]});
	}
}

void Parser::add_arg(std::string longhand, std::vector<Constraint> constraints, std::string shorthand, bool required, std::string description) {
    _args.push_back(Arg{constraints, shorthand, longhand, description, required, {}});
}

bool Parser::check_validity(std::string *const err_msg) {
	return true;
}

template <typename T>
T Parser::get(std::string hand) const {
    return T();
}

template <typename T>
T Parser::get_shorthand(std::string shorthand) const {
    return T();
}

template <typename T>
T Parser::get_longhand(std::string longhand) const {
    return T();
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
