#include "Parser.hpp"
#include <string>
#include <sstream>

int main(int argc, char **argv) {
	std::cout << "Passing arguments to parser... " << std::endl;
	Parser parser(argc, argv);	
	parser.set_bool("hello", "hi", "");
	std::cout << "Parser recieved: " << parser.get_as_string() << std::endl;
	std::cout << std::boolalpha << parser.valid() << std::endl;
	return 0;
}
