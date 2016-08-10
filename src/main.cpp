#include "Parser.hpp"
#include <string>
#include <iostream>
int main(int argc, char **argv) {
	Parser parser(argc, argv);	

	parser.set_bool("run", "r", "");
	parser.set_positional("coordinates", 1, 2, "");


	std::cout << "Parser recieved: " << parser.get_as_string() << std::endl;
	if (!parser.valid()) {
		std::cerr << "Arguments invalid" << std::endl;
		return 1;
	}
	parser.parse();
	if (parser.get_bool("run")) {
		std::cout << "RUNNING" << std::endl;
		std::vector<std::string> coords = parser.get_positional("coordinates");
		std::cout << "Coordinates Recieved: (" << coords[0] << ", " << coords[1] << ")" << std::endl;
	}
	return 0;
}
