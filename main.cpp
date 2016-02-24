#include "Parser.hpp"
#include <string>
#include <sstream>

int main(int argc, char **argv) {
	std::cout << "Passing arguments to parser... " << std::endl;
	Parser parser(argc, argv);
	parser.add_arg("longhand", {}, "S", true);
	std::cout << parser.get_raw() << std::endl;
	std::cout << std::boolalpha << parser.check_validity() << std::endl;
	return 0;
}
