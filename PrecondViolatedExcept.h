/** @file PrecondViolatedExcept.h
 * @class PrecondViolatedExcept
 * Custom exception class for precondition violations. Inherits from std::logic_error to signal logical errors during runtime. */

#ifndef PRECOND_VIOLATED_EXCEPT_
#define PRECOND_VIOLATED_EXCEPT_

#include <stdexcept>
#include <string>

class PrecondViolatedExcept : public std::logic_error
{
public:
    /** Constructs a PrecondViolatedExcept with a specified error message.
     * @pre None
     * @post None
     * @param message The error message describing the precondition violation. */
    PrecondViolatedExcept(const std::string& message = "");
};

#include "PrecondViolatedExcept.cpp"
#endif