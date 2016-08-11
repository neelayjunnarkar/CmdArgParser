#include <numeric>
#include <iostream>

#include "Parser.hpp"

Parser::Parser(std::vector<std::string> args):
	_raw_args(args) {

}

Parser Parser::from_raw(int argc, char **argv) {
	std::vector<std::string> strs;
	for (int i = 1; i < argc; ++i) {
		strs.push_back(std::string{argv[i]});
	}
	return Parser(strs);
}

bool Parser::valid() const {
	//Minimum length = count of all required arguments
	int min_len = 0;
	for (const PosArg &arg : _pos_args) {
		min_len += arg.count;
	}
	if (_raw_args.size() < min_len) {
		std::cout << "Error: too few arguments passed" << std::endl;
		return false;
	}

	for (int i = 0; i < _raw_args.size(); ++i) {
		bool is_valid = false;
		for (const BoolArg &arg : _bool_args) {
			if (_raw_args[i] == "--"+arg.lh || _raw_args[i] == "-"+arg.sh) {
				is_valid = true;
				break;
			}
		}
		for (const PosArg &arg : _pos_args) {
			if (i >= arg.first && i < arg.first + arg.count) {
				if (is_valid) { //already a valid bool arg. Cannot overlap
					std::cout << "Error: line 34" << std::endl;
					return false;
				}
				is_valid = true;
			}
		}
		if (!is_valid) {
			std::cout << "Error: line 42; did not appear" << std::endl;
			return false;
		}		
	}
	return true;
}

void Parser::parse() {
	for (int i = 0; i < _raw_args.size(); ++i) {
		for (BoolArg &arg : _bool_args) {
			if (_raw_args[i] == "--"+arg.lh || _raw_args[i] == "-"+arg.sh) {
				arg.value = true;
			}
		}
	}
	for (PosArg &arg : _pos_args) {
		for (int i = arg.first; i < arg.first+arg.count; ++i) {
			arg.values.push_back(_raw_args[i]);
		}
	}
}

std::string Parser::get_as_string() const {
	return std::accumulate(_raw_args.begin(), _raw_args.end(), std::string(""), 
		[] (const std::string &lhs, const std::string &rhs) { 
			return lhs + std::string(" ") + rhs; 
		}
	);
}

bool Parser::get_bool(const std::string &name) {
	for (const BoolArg &arg : _bool_args) {
		if (name == arg.lh || name == arg.sh)
			return arg.value;
	}
	return false;
}

std::vector<std::string> Parser::get_positional(const std::string &name) {
	for (const PosArg &arg : _pos_args) {
		if (name == arg.id)
			return arg.values;
	}
	return {};
}

void Parser::set_bool(std::string lh, std::string sh, std::string desc) {
	_bool_args.push_back(BoolArg{lh, sh, desc});
}

void Parser::set_positional(std::string internal_id, int first, int count, std::string desc) {
	_pos_args.push_back(PosArg{internal_id, first, count, desc});
}
