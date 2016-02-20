#include <iostream>
#include <string>
#include <vector>
#include <functional>

class Parser {
public:
	using Constraint = std::function<bool(std::vector<std::string>)>;

	Parser(int argc, char **argv);

	void add_arg(std::string longhand, std::vector<Constraint> constraints={}, std::string shorthand="", std::string description="");
	bool check_validity(std::string *const err_msg = nullptr);

	std::string get_raw() const;
private:

	struct Arg {
		std::vector<Constraint> constraints;
		std::string shorthand;
		std::string longhand;
		std::string description;
	};

	std::vector<std::string> _raw_args;
	std::vector<Arg> _args;
};
