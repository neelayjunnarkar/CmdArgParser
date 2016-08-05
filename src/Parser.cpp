#include "Parser.hpp"

Parser::Parser(int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		_raw_args.push_back(std::string{argv[i]});
	}
}

bool Parser::valid() const {
	for (const std::string &raw_arg : _raw_args) {
		bool is_valid = false;
		for (const BoolArg &arg : _bool_args) {
			if (raw_arg == "--"+arg.lh || raw_arg == "-"+arg.sh) {
				is_valid = true;
				break;
			}
		}
		if (!is_valid)
			return false;
	}
	return true;
}

void Parser::parse() {
	for (const std::string &raw_arg : _raw_args) {
		for (BoolArg &arg : _bool_args) {
			if (raw_arg == "--"+arg.lh || raw_arg == "-"+arg.sh) {
				arg.value = true;
			}
		}
	}
}

std::string Parser::get_as_string() const {
	if (_raw_args.size() == 0)
		return "";

	std::string list = _raw_args[0];

	for (int i = 1; i < _raw_args.size(); ++i) {
		list += std::string{" "} + _raw_args[i];
	}
	return list;
}

bool Parser::get_bool(const std::string &name) {
	for (const BoolArg &arg : _bool_args) {
		if (name == arg.lh || name == arg.sh)
			return arg.value;
	}
	return false;
}
void Parser::set_bool(std::string lh, std::string sh, std::string desc) {
	_bool_args.push_back(BoolArg{lh, sh, false, desc});
}
