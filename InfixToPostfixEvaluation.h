/** @file InfixToPostfixEvaluation.h
 * @class InfixToPostfixEvaluation 
 * Declaration of the InfixToPostfixEvaluation class, which provides functionality to convert infix expressions to postfix, evaluate postfix expressions, and manage variable values */

#ifndef INFIX_TO_POSTFIX_EVALUATION_
#define INFIX_TO_POSTFIX_EVALUATION_

#include <string>
#include <cctype>
#include <stdexcept>
#include <fstream>
#include "InfixToPostfixInterface.h"
#include "OurQueue.h"
#include "LinkedStack.h"

class InfixToPostfixEvaluation : public InfixToPostfixInterface
{
private:
    /** Capacity of the variable values array */
    static constexpr size_t CAPACITY = 6;

    /** Queue to store the postfix expression */
    OurQueue<char> postfixExpQueue;

    /** Stack to manage operators during conversion */
    LinkedStack<char> operatorStack;

    /** Array to store values of variables a-f. All values are initially set to 0. */
    int variableValues[CAPACITY];

    /** Helper function to determine the precedence of an operator.
     * @pre None
     * @post None
     * @param operatorChar The operator character to check.
     * @return An integer representing the precedence level. */
    int precedence(char operatorChar) const noexcept;

public:
    /** Default constructor */
    InfixToPostfixEvaluation();

    /** Virtual destructor */
    virtual ~InfixToPostfixEvaluation() = default;

    /** Converts an infix expression to a postfix expression.
     * @pre Assumes infix expression is valid.
     * @post Infix expression is converted to postfix. Infix expression is unchanged.
     * @param infixExpression The infix expression to convert. */
    void convertInfixToPostfix(const std::string& infixExpression) noexcept override;

    /** Retrieves the converted postfix expression.
     * @pre None
     * @post None
     * @return A string representing the postfix expression. */
    std::string getPostfixExpression() const noexcept override;

    /** Reads variable values from a specified file and stores them in the variableValues array.
     * @pre Assumes file exists and contains at least the same number of integer values as CAPACITY
     * @post variableValues it filled with integer values from file. File is unchanged.
     * @param filename The name of the file containing variable values.
     * @throw std::runtime_error If the file cannot be opened.
     * @throw std::runtime_error If the file does not contain enough values. */
    void readValuesFromFile(const std::string& filename) override;

    /** Clears the values in the variableValues array by setting all values to 0.
     * @pre None
     * @post Array values are all 0. */
    void clearVariableValues() noexcept override;

    /** Concatenates and returns variable values to a string.
     * @pre None
     * @post Values are unchanged in array.
     * @return Returns values as a string. If values are zero in the variableVaules array, all values are 0 in string. */
    std::string getVariableValues() const noexcept override;

    /**
     * Evaluates the current postfix expression stored in `postfixExpQueue`.
     * @pre `postfixExpQueue` contains a valid postfix expression.
     * @post Returns the evaluated result of the postfix expression.
     * @return The integer result of the postfix expression evaluation.
     * @throws std::runtime_error If the postfix expression is invalid.
     * @throws std::runtime_error If an unknown operator is encountered.
     * @throws std::runtime_error If division by zero occurs. */
    double evaluatePostfixExpression() override;
};

#include "InfixToPostfixEvaluation.cpp"
#endif
