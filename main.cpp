#include "Parser.hpp"
#include <string>
#include <sstream>

int main(int argc, char **argv) {
	std::cout << "Passing arguments to parser... " << std::endl;
	Parser parser(argc, argv);	
	return 0;
}
