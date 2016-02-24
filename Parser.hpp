#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <sstream>
#include <algorithm>

class Parser {
public:
	using Constraint = std::function<bool(std::vector<std::string>)>;

	Parser(int argc, char **argv);

	void add_arg(std::string longhand, std::vector<Constraint> constraints={}, std::string shorthand="", bool required = false, std::string description="");
		
	bool check_validity(std::string *const err_msg = nullptr);

	void parse(std::string *const err_msg = nullptr);

	template <typename T>
	T get(std::string hand) const;
    
	template <typename T>
	T get_shorthand(std::string shorthand) const;
    
	template <typename T>
	T get_longhand(std::string longhand) const;
     
	std::string get_raw() const;
private:

	struct Arg {
		std::vector<Constraint> constraints;
		std::string shorthand;
		std::string longhand;
		std::string description;
		bool required;        
		std::vector<std::string> arguments; //arguments to the argument to the program
	};

	std::vector<std::string> _raw_args;
	std::vector<Arg> _args;
};
