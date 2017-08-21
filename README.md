# CmdArgParser
C++ utilities for easy parsing of and retrieval of values from arguments to the program by Neelay Junnarkar

## Boolean Arguments

* Flags—parser checks whether the flag is passed or is not, and will return true and false respectively
* Are optional

Format:

* set_bool:
	* long-hand: string
	* short-hand: string
	* description: string, description of what the labeled argument is and what it does
* get_bool:
	* name: string, either long-hand or short-hand
	* return value: bool, true if the flag was passed to the program, false otherwise

Example code:
```
...
parser.set_bool("run", "r", "description—will not be used right now");
...
if (parser.get_bool("r")) { // or "run"
	...
}
```
Example using boolean flags:
```
./executable -r
```
or
```
./executable --run
```

## Labeled Arguments

* Series of values of specified count **after** a label
* Can be made either optional **or** required

Format:

* set_labeled:
	* long-hand: string
	* short-hand: string
	* count: int, number of values (excluding flag)
	* required: bool, whether values must be passed or not (will error if true and not passed)
	* description: string, description of what the labeled argument is and what it does
* get_labeled:
	* name: string, either long-hand or short-hand
	* return value: vector of strings
	
Example code:
```
...
parser.set_labeled("coordinates", "c", 2, true, "description—will not be used right now");
parser.set_labeled("elevation", "e", 1, true, "description—will not be used right now");
...
std::vector<std::string> coords = parser.get_labeled("coordinates");
std::cout << "Coordinates: (" << coords[0] << ", " << coords[1] << ")" << std::endl;
std::cout << "Elevation: " << parser.get_labeled("e")[0] << std::endl;
```

Example using labeled arguments:
```
./executable -c 0 1 -e 2
```
or 
```
./executable -e 2 -c 0 1
```
Can use any mix of long and short hand

## Positional Arguments

* A series of values of specified count at a specific index (by argument) in the input.
* Do not have a label when passing the arguments, but do have an internal ID to be used by the program
* Are **always** required to be passed if created within the program

Format:

* set_positional:
	* internal-id: string, ID by which the positional argument will be referred to within the program
	* fist: int, index of first value in the series
	* count: int, number of values (excluding flag)
	* description: string, description of what the labeled argument is and what it does
* get_positional:
	* name: string, either long-hand or short-hand
	* return value: vector of strings

Example code:
```
...
parser.set_positional("coordinates", 0, 2, "description—not used right now");
...
std::cout << "Coordinates: (" << parser.get_positional("coordinates")[0] << ", " << parser.get_positional("coordinates")[1] << ")" << std::endl;
```
Example using positional arguments:
```
./executable 29 10
```

Note: May be removed in a future version in total favor of labeled arguments.

## Full Example

```
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
```
