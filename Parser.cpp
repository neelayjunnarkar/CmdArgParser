#include "Parser.hpp"

template <typename T>
Parser::Arg<T>::Arg(std::string internal_id, std::vector<int> poss, std::vector<Constraint> cstrts, bool req, std::string desc) :
    _Arg({internal_id}, desc),
    poss{new std::vector<int>{poss}},
    cstrts{new std::vector<Constraint>{cstrts}},
    req{new bool{req}} {      
}
template <typename T>
Parser::Arg<T>::Arg(std::string lh, std::string sh, std::string desc) :
    _Arg({lh, sh}, desc),
    poss{nullptr},
    cstrts{nullptr},
    req{nullptr} {
}
template <typename T>
Parser::Arg<T>::Arg(std::string lh, std::string sh, std::vector<Constraint> cstrts, bool req, std::string desc) :
    _Arg({lh, sh}, desc),
    poss{nullptr},
    cstrts{new std::vector<Constraint>{cstrts}},
    req{new std::vector<Constraint>{req}} {
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
