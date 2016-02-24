#include "Parser.hpp"
#include <string>
#include <sstream>

int main(int argc, char **argv) {
	std::cout << "Passing arguments to parser... " << std::endl;
	Parser parser(argc, argv);
	parser.add_arg("longhand", {}, "S", "THIS IS AN ARGUMENT");
	std::cout << parser.get_raw() << std::endl;
	return 0;
}
