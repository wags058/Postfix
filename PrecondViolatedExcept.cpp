/** @file PrecondViolatedExcept.cpp
 * PrecondViolatedExcept throws a precondition violation error and message.
 * @author Stephen Wagner
 * @date 11/5/2024
 * CSCI 591 Section 1 */

#include "PrecondViolatedExcept.h"

// Constructor initializes with a custom message, forwarding it to std::logic_error
PrecondViolatedExcept::PrecondViolatedExcept(const std::string& message)
    : std::logic_error("Precondition Violated Exception: " + message)
{ }  // end constructor