#include "Parser.hpp"

Parser::Parser(int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		_raw_args.push_back(std::string{argv[i]});
	}
}

bool Parser::check_validity(std::string *const err_msg) {
	/*
	 * Finds iterator of next string in _raw_args that is an argument (has - or --)
	 */
	auto next_arg = [&](std::vector<std::string>::iterator arg_it) {
		
	};

	for (Arg &arg : _args) {
		auto arg_it = std::find(_raw_args.begin(), _raw_args.end(), "--"+arg.longhand);	
		if (arg_it != _raw_args.end()) {
								
			continue;
		}
		arg_it = std::find(_raw_args.begin(), _raw_args.end(), "-"+arg.shorthand);
		if (arg_it != _raw_args.end()) {

			continue;
		}
		if (arg.required == true)
			return false;
	}

	return true;
}

void Parser::parse(std::string *const err_msg) {

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
