#ifndef MSGEXCEPTION_HPP
#define MSGEXCEPTION_HPP

#include <exception>
#include <cstring>

struct MsgException : public std::exception {
	char *msg;
	MsgException(const char *_msg) {
		msg = new char[strlen(_msg)];
		strcpy(msg, _msg);
	};
	~MsgException() throw() {
		delete[] msg;
	};
	const char* what() const throw() { return msg; }; 
};

#endif