#include "Constraint.hpp"

struct Argument {
    std::string description;
    std::string longhand;
    std::string shorthand;
    bool required;
    std::vector<Constraint> constraint;    
};