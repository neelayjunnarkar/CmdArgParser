#include "Parser.hpp"
#include <string>
#include <iostream>
int main(int argc, char **argv) {
	Parser parser = Parser::from_env(argc, argv);	

	parser.set_labeled("coordinates", "c", 2, true, "");
	parser.set_labeled("elevation", "e", 1, true, "");
	parser.set_labeled("aspect", "a", 1, true, "");
	parser.set_labeled("slope", "s", 1, true, "");
	parser.set_labeled("optional", "o", 1, false, "");
	
	std::cout << "Parser recieved: " << parser.get_as_string() << std::endl;
	if (!parser.valid()) {
		std::cerr << "Arguments invalid" << std::endl;
		return 1;
	}
	parser.parse();

	std::vector<std::string> coords = parser.get_labeled("coordinates");
	std::cout << "Coordinates: (" << coords[0] << ", " << coords[1] << ")" << std::endl;

	std::cout << "Elevation: " << parser.get_labeled("e")[0] << std::endl;
	std::cout << "Aspect: " << parser.get_labeled("a")[0] << std::endl;
	std::cout << "Slope: " << parser.get_labeled("s")[0] << std::endl;
	if (!parser.get_labeled("o").empty()) {
		std::cout << "Recieved optional value: " << parser.get_labeled("o")[0] << std::endl;
	}
	return 0;
}
