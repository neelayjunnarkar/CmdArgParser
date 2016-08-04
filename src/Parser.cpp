#include "Parser.hpp"

Parser::_Arg::_Arg(const std::vector<std::string> &name, const std::string &desc) :
	name{name},
	desc{desc} { 
}
		
Parser::Arg::Arg(std::string internal_id, std::vector<int> poss, bool req, std::string desc) :
	_Arg({internal_id}, desc),
	poss{new std::vector<int>{poss}},
	req{new bool{req}},
	type{Type::POSITIONAL} {      
}
Parser::Arg::Arg(std::string lh, std::string sh, std::string desc) :
	_Arg({lh, sh}, desc),
	poss{nullptr},
	req{nullptr},
	type{Type::BOOL} {
}
Parser::Arg::Arg(std::string lh, std::string sh, int count, bool req, std::string desc) :
	_Arg({lh, sh}, desc),
	poss{nullptr},
	type{Type::LABELED} {
}

Parser::Parser(int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		_raw_args.push_back(std::string{argv[i]});
	}
}

bool Parser::valid() const {
	for (const std::string &raw_arg : _raw_args) {
		bool is_valid = false;
		for (const _Arg *const arg : _args) {
			if ((*(Arg*)(arg)).type == Arg::Type::BOOL) {
				if (raw_arg == "--"+(*arg).name[_Arg::lh] || raw_arg == "-"+(*arg).name[_Arg::sh]) {
					is_valid = true;
					break;
				}
			}
		}
		if (!is_valid)
			return false;
	}
	return true;
}

void Parser::parse() {
	for (const std::string &raw_arg : _raw_args) {
		for (const _Arg *const arg : _args) {
			if ((*(Arg*)(arg)).type == Arg::Type::BOOL) {
				if (raw_arg == "--"+(*arg).name[_Arg::lh] || raw_arg == "-"+(*arg).name[_Arg::sh]) {
					((Arg*)arg)->arg_vals.push_back("1");
					break;
				}
			}
		}
	}    
	for (const _Arg *const arg : _args) {
		if ((*(Arg*)(arg)).type == Arg::Type::BOOL) {
			if (((Arg*)arg)->arg_vals.empty()) {
				((Arg*)arg)->arg_vals.push_back("0");
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

std::vector<std::string> Parser::get(const std::string &name) const {
	for (const _Arg *const arg : _args) {
		for (const std::string &arg_name : ((Arg*)arg)->name) {
			if (name == arg_name) {
				return ((Arg*)arg)->arg_vals; 
			}
		}
	}
	return {};
}

void Parser::set_bool(std::string lh, std::string sh, std::string desc) {
	_args.push_back(new Arg{lh, sh, desc});
}
