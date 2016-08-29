#include "Parser.hpp"
#include <string>
#include <iostream>
int main(int argc, char **argv) {
	Parser parser = Parser::from_raw(argc-1, argv+1);	

	parser.set_bool("run", "r", "");
	parser.set_labeled("coordinates", "c", 2, true, "");
	parser.set_labeled("eas", "eas", 3, true, ""); 
	std::cout << "Parser recieved: " << parser.get_as_string() << std::endl;
	if (!parser.valid()) {
		std::cerr << "Arguments invalid" << std::endl;
		return 1;
	}
	parser.parse();
	if (parser.get_bool("run")) {
		std::cout << "RUNNING" << std::endl;

		std::vector<std::string> coords = parser.get_labeled("coordinates");
		std::cout << "Coordinates: (" << coords[0] << ", " << coords[1] << ")" << std::endl;

		std::vector<std::string> eas = parser.get_labeled("eas");
		std::cout << "Elevation: " << eas[0] << std::endl;
		std::cout << "Aspect: " << eas[1] << std::endl;
		std::cout << "Slope: " << eas[2] << std::endl;

	}
	return 0;
}
