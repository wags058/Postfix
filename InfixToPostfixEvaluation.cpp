/** @file InfixToPostfixEvaluation.cpp
 * InfixToPostfixEvaluation converts an infix expression to postfix and evaluates the resulting postfix expression.
 * @author Stephen Wagner
 * @date 11/5/2024
 * CSCI 591 Section 1 */

#include "InfixToPostfixEvaluation.h"

InfixToPostfixEvaluation::InfixToPostfixEvaluation()
{} // end default constructor

int InfixToPostfixEvaluation::precedence(char operatorChar) const noexcept
{
    if (operatorChar == '+' || operatorChar == '-')
    {
        return 1; // Operators '+' and '-' have a precedence of 1
    }
    if (operatorChar == '*' || operatorChar == '/')
    {
        return 2; // Operators '*' and '/' have a precedence of 2
    }
    return 0;
} // end precedence

void InfixToPostfixEvaluation::convertInfixToPostfix(const std::string& infixExpression) noexcept
{
    postfixExpQueue = OurQueue<char>();       // Initialize an empty queue
    operatorStack = LinkedStack<char>();      // Initialize an empty stack

    for (char currentChar : infixExpression) // Range based loop over infix expression
    {
        currentChar = std::tolower(currentChar);  // Convert to lowercase if uppercase

        if (std::isalpha(currentChar)) 
        {
            postfixExpQueue.enqueue(currentChar);  // Enqueue operand to postfix expression
        }
        else 
        {
            switch (currentChar) 
            {
            case '(':  // Opening parenthesis
                operatorStack.push(currentChar);  // Save '(' on stack
                break;

            case '+': case '-': case '*': case '/':  // Valid operators
                while (!operatorStack.isEmpty() && operatorStack.peek() != '(' &&
                    precedence(currentChar) <= precedence(operatorStack.peek())) 
                {
                    char nextOperator = operatorStack.peek();
                    postfixExpQueue.enqueue(nextOperator);  // Enqueue operator
                    operatorStack.pop();
                }
                operatorStack.push(currentChar);  // Save the operator on stack
                break;

            case ')':  // Closing parenthesis
                while (operatorStack.peek() != '(') 
                {
                    char nextOperator = operatorStack.peek();
                    postfixExpQueue.enqueue(nextOperator);  // Enqueue operator
                    operatorStack.pop();
                }
                operatorStack.pop();  // Remove the open parenthesis
                break;
            }
        }
    }

    // Add remaining operators to postfix expression
    while (!operatorStack.isEmpty()) 
    {
        char nextOperator = operatorStack.peek();
        postfixExpQueue.enqueue(nextOperator);  // Enqueue remaining operators
        operatorStack.pop();
    }
} // end convertInfixToPostfix

std::string InfixToPostfixEvaluation::getPostfixExpression() const noexcept 
{
    // Convert the contents of postfixExpQueue to a string for output
    OurQueue<char> tempQueue = postfixExpQueue;  // Copy the queue to avoid modifying the original
    std::string postfixExpression;

    while (!tempQueue.isEmpty()) 
    {
        postfixExpression += tempQueue.peekFront();
        tempQueue.dequeue();
    }

    return postfixExpression;
} // end getPostfixExpression

void InfixToPostfixEvaluation::readValuesFromFile(const std::string& filename)
{
    std::ifstream file(filename); // Open the file
    if (!file) // Throw error if the file could not be opened
    {
        throw std::runtime_error("Could not open file: " + filename);
    }

    for (size_t i = 0; i < CAPACITY; ++i) // Add values from the file into array
    {
        if (!(file >> variableValues[i])) 
        {
            throw std::runtime_error("File does not contain enough values."); // Throw error if there are not enough values
        }
    }
} // end readValuesFromFile

void InfixToPostfixEvaluation::clearVariableValues() noexcept
{
    for (size_t i = 0; i < CAPACITY; ++i) // Set values to zero to clear the array
    {
        variableValues[i] = 0;
    }
} // end clearVariableValues

std::string InfixToPostfixEvaluation::getVariableValues() const noexcept
{
    std::string result = "Variable values : "; // Delare string to concatenate values
    for (size_t i = 0; i < CAPACITY; ++i) 
    {
        result += " " + std::to_string(variableValues[i]); // Concatenate all values from the array to the string
    }
    return result; // Return string of values
} // end getVariableValues

double InfixToPostfixEvaluation::evaluatePostfixExpression() 
{
    LinkedStack<double> evaluationStack;  // Stack to hold intermediate results

    // Loop through each character in the postfix expression queue
    while (!postfixExpQueue.isEmpty()) 
    {
        char currentChar = postfixExpQueue.peekFront();
        postfixExpQueue.dequeue();

        if (std::isalpha(currentChar))  // Operand
        {
            int variableIndex = currentChar - 'a';  // Convert variables to corresponding index
            evaluationStack.push(variableValues[variableIndex]);
        }
        else  // Operator
        {
            if (evaluationStack.isEmpty()) throw std::runtime_error("Invalid postfix expression");

            // Pop the top two operands
            double operand2 = evaluationStack.peek();
            evaluationStack.pop();

            if (evaluationStack.isEmpty()) throw std::runtime_error("Invalid postfix expression");
            double operand1 = evaluationStack.peek();
            evaluationStack.pop();

            double result = 0;

            // Perform the operation based on the operator
            switch (currentChar) 
            {
            case '+': result = operand1 + operand2; break;
            case '-': result = operand1 - operand2; break;
            case '*': result = operand1 * operand2; break;
            case '/':
                if (operand2 == 0) throw std::runtime_error("Division by zero");
                result = operand1 / operand2;
                break;
            default:
                throw std::runtime_error("Unknown operator encountered");
            }

            // Push the result back onto the stack
            evaluationStack.push(result);
        }
    }

    // The final result should be the only element in the stack
    if (evaluationStack.isEmpty()) throw std::runtime_error("Invalid postfix expression");

    double finalResult = evaluationStack.peek();
    evaluationStack.pop();

    // If the stack is not empty, it means the postfix expression was invalid
    if (!evaluationStack.isEmpty()) throw std::runtime_error("Invalid postfix expression");

    return finalResult;
} // end evaluatePostfixExpression
