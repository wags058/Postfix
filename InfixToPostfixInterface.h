/** @file InfixToPostfixInterface.h
 * @class InfixToPostfixInterface
 * Interface for classes  that convert infix expressions to postfix, evaluate postfix expressions, and manage variable values. */

#ifndef INFIX_TO_POSTFIX_INTERFACE_
#define INFIX_TO_POSTFIX_INTERFACE_

#include <string>

class InfixToPostfixInterface
{
public:
    /** Converts an infix expression to a postfix expression.
     * @pre Assumes infix expression is valid.
     * @post Infix expression is converted to postfix.  Infix expression is unchanged.
     * @param infixExpression The infix expression to convert. */
    virtual void convertInfixToPostfix(const std::string& infixExpression) = 0;

    /** Retrieves the converted postfix expression.
     * @pre None
     * @post None
     * @return A string representing the postfix expression. */
    virtual std::string getPostfixExpression() const = 0;

    /** Virtual destructor for the interface. */
    virtual ~InfixToPostfixInterface() = default;

    /** Reads variable values from a specified file.
     * @pre Assumes file contains enough values for variables and all values are integers.
     * @post File is unchanged.
     * @param filename The name of the file containing variable values. */
    virtual void readValuesFromFile(const std::string& filename) = 0;

    /** Clears the current variable values.
     * @pre None
     * @post The variable values are cleared. */
    virtual void clearVariableValues() = 0;

    /** Outputs the current variable values to the console.
     * @pre None
     * @post Values will be unchanged.
     * @return A string containing variable values. If not values were read from a file, all values will be zero. */
    virtual std::string getVariableValues() const = 0;

    /** Evaluates the postfix expression based on the current variable values.
     * @pre Assumes a valid postfix expression is available using operands a-f and operators +,-,*,/. All values used for variables must be integers
     * @post Does not change the postfix expression.
     * @return The result of the evaluation as an integer. */
    virtual double evaluatePostfixExpression() = 0;
};

#endif
