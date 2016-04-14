#include "Parser.hpp"

Parser::_Arg::_Arg(const std::vector<std::string> &name, const std::string &desc) :
	name{name},
	desc{desc} { 
}
		
template <typename T>
Parser::Arg<T>::Arg(std::string internal_id, std::vector<int> poss, std::vector<Constraint> cstrts, bool req, std::string desc) :
	_Arg({internal_id}, desc),
	poss{new std::vector<int>{poss}},
	cstrts{new std::vector<Constraint>{cstrts}},
	req{new bool{req}},
	type{Type::POSITIONAL} {      
}
template <typename T>
Parser::Arg<T>::Arg(std::string lh, std::string sh, std::string desc) :
	_Arg({lh, sh}, desc),
	poss{nullptr},
	cstrts{nullptr},
	req{nullptr},
	type{Type::BOOL} {
}
template <typename T>
Parser::Arg<T>::Arg(std::string lh, std::string sh, std::vector<Constraint> cstrts, bool req, std::string desc) :
	_Arg({lh, sh}, desc),
	poss{nullptr},
	cstrts{new std::vector<Constraint>{cstrts}},
	req{new std::vector<Constraint>{req}},
	type{Type::LABELED} {
}

Parser::Parser(int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		_raw_args.push_back(std::string{argv[i]});
	}
}

bool Parser::valid() const {
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
