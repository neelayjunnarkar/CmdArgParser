#include "Parser.hpp"

int main(int argc, char **argv) {
	std::cout << "Passing arguments to parser... " << std::endl;
	Parser parser(argc, argv);
	std::cout << parser.get_raw() << std::endl;
	return 0;
}
