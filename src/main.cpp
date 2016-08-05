#include "Parser.hpp"
#include <string>
#include <iostream>
int main(int argc, char **argv) {
	std::cout << "Passing arguments to parser... " << std::endl;
	Parser parser(argc, argv);	
	parser.set_bool("run", "r", "");
	std::cout << "Parser recieved: " << parser.get_as_string() << std::endl;
	if (!parser.valid()) {
		std::cerr << "Arguments invalid" << std::endl;
		return 1;
	}
	parser.parse();
	if (parser.get_bool("run")) {
		std::cout << "RUNNING" << std::endl;
	}
	return 0;
}
