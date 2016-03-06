#include <exception>

struct MsgException : public std::exception {
	std::string msg;
	MsgException(std::string msg) : msg{msg} {};
	~MsgException() throw() {};
	const char * what() const throw() { return msg.c_str(); }; 
};
