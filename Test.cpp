/** @file Test.cpp
 * Tests valid, boundary, invalid values, and user testing interface.
 * @author Stephen Wagner
 * @date 11/5/2024
 * CSCI 591 Section 1 */

#include <iostream>
#include "InfixToPostfixEvaluation.h"

using namespace std;

int main()
{
	// Testing valid values
	cout << "=== Valid Values ===" << endl;

	// Create an instance of the class for testing
	InfixToPostfixEvaluation evaluator;

	// Testing that the variableValues array contains zeros
	cout << evaluator.getVariableValues() << endl;
	cout << "Should be all zeros: 0 0 0 0 0 0" << endl << endl;

	// Testing reading file for variable values
	evaluator.readValuesFromFile("variables.txt");

	// Outputting the variable values again
	cout << evaluator.getVariableValues() << endl;
	cout << "Should be numbers: 5 10 15 20 25 30" << endl << endl;

	// Testing clear variable values
	evaluator.clearVariableValues();
	cout << evaluator.getVariableValues() << endl;
	cout << "Should be all zeros: 0 0 0 0 0 0" << endl << endl;

	// Setting variable values for testing
	evaluator.readValuesFromFile("variables.txt");
	cout << evaluator.getVariableValues() << endl;
	cout << "Should be numbers: 5 10 15 20 25 30" << endl << endl;

	// Creating an array with required test infix expressions
	std::string testExpressions[] =
	{
		"a+b*c",           // Example (a)
		"(a+b)*c",         // Example (b)
		"a+b*c-d",         // Example (c)
		"a+b*(c-d)",       // Example (d)
		"(a+b)*(c-d)",     // Example (e)
		"a+b+c+d",         // Example (f)
		"a+b*c/d-e+f",     // Example (g)
		"a*(b+c)*(d-e)+f"  // Example (h)
	};

	// Loop through each expression, convert, and evaluate
	for (const std::string& infixExpr : testExpressions)
	{
		cout << "Infix Expression: " << infixExpr << endl;
		evaluator.convertInfixToPostfix(infixExpr);
		cout << "Postfix Expression: " << evaluator.getPostfixExpression() << endl;
		double result = evaluator.evaluatePostfixExpression();
		cout << "Evaluation Result: " << result << endl << endl;
	}
	cout << endl;

	// Testing boundary values
	cout << "=== Boundary Values ===" << endl;

	// Testing a small expression
	evaluator.convertInfixToPostfix("a");
	cout << "Postfix expression: " << evaluator.getPostfixExpression() << endl;
	cout << "Should be: a" << endl;
	double result = evaluator.evaluatePostfixExpression();
	cout << "Result is: " << result << endl;
	cout << "Should be: 5" << endl << endl;

	// Testing a large expression
	evaluator.convertInfixToPostfix("a+b+c+d+e+f");
	cout << "Postfix expression: " << evaluator.getPostfixExpression() << endl;
	cout << "Should be: ab+c+d+e+f+" << endl;
	result = evaluator.evaluatePostfixExpression();
	cout << "Result is: " << result << endl;
	cout << "Should be: 105" << endl << endl;

	// Testing an expression resulting in zero
	evaluator.convertInfixToPostfix("a-a");
	cout << "Postfix expression: " << evaluator.getPostfixExpression() << endl;
	cout << "Should be: aa-" << endl;
	result = evaluator.evaluatePostfixExpression();
	cout << "Result is: " << result << endl;
	cout << "Should be: 0" << endl << endl;

	// Testing invalid values
	cout << "=== Invalid Values ===" << endl;

	// Changing variable values for additional boundary cases
	evaluator.readValuesFromFile("boundaryVariables.txt");

	// Outputting the variable values again
	cout << evaluator.getVariableValues() << endl;
	cout << "Should be numbers: 5 0 15 20 25 30" << endl << endl;

	// Using a try catch block to test division by zero
	try
	{
		evaluator.convertInfixToPostfix("a/b");
		cout << "Postfix expression: " << evaluator.getPostfixExpression() << endl;
		cout << "Should be: ab/" << endl;

		result = evaluator.evaluatePostfixExpression();
		cout << "Result is: " << result << endl;
		cout << "Expected output: Division by zero error handled" << endl << endl;
	}
	catch (const std::runtime_error& error) {
		cout << "Caught exception: " << error.what() << endl;
		cout << "Expected output: Division by zero" << endl << endl;
	}

	// Using a try catch block to test for invalid expression
	try
	{
		evaluator.convertInfixToPostfix("+");
		cout << "Postfix expression: " << evaluator.getPostfixExpression() << endl;
		cout << "Should be: +" << endl;

		result = evaluator.evaluatePostfixExpression();
		cout << "Result is: " << result << endl;
	}
	catch (const std::runtime_error& error)
	{
		cout << "Caught exception: " << error.what() << endl;
		cout << "Expected output: Invalid postfix expression" << endl << endl;
	}

	// Testing no operators
	try
	{
		evaluator.convertInfixToPostfix("abcdef");
		cout << "Postfix expression: " << evaluator.getPostfixExpression() << endl;
		cout << "Should be: abcdef" << endl;

		result = evaluator.evaluatePostfixExpression();
		cout << "Result is: " << result << endl;
		cout << "Expected output: Sum of all variable values if valid" << endl << endl;
	}
	catch (const std::runtime_error& error)
	{
		cout << "Caught exception: " << error.what() << endl;
		cout << "Expected output: Exception handled for invalid expression" << endl << endl;
	}

	try {
		// Trying to change variables with an invalid input file
		evaluator.readValuesFromFile("invalidVariables.txt");

		// Outputting the variable values again
		cout << evaluator.getVariableValues() << endl;
		cout << "Should be numbers: 5 10 15" << endl << endl;
	}
	catch (const std::runtime_error& error) {
		cout << "Caught exception: " << error.what() << endl;
		cout << "Expected output: file does not contain enough values" << endl << endl;
	}
	cout << endl;
	
	// User testing interface
	cout << "=== User Input Testing ===" << endl;

	// Changing variables back to a valid file
	evaluator.readValuesFromFile("variables.txt");

	// Outputting the variable values again
	cout << evaluator.getVariableValues() << endl;
	cout << "Should be numbers: 5 10 15 20 25 30" << endl << endl;

	// Prompting user for expressions
	string userInput;
	cout << "Type a valid infix expression using letters 'a' through 'f' and binary operators to convert and evaluate, or type 'quit' to end." << endl;
	while (true)
	{
		cout << "Enter an infix expression (or 'quit' to exit): ";
		getline(cin, userInput);

		if (userInput == "quit")
		{
			cout << "Exiting user test program." << endl;
			break;
		}

		try
		{
			evaluator.convertInfixToPostfix(userInput);
			cout << "Postfix Expression: " << evaluator.getPostfixExpression() << endl;

			double result = evaluator.evaluatePostfixExpression();
			cout << "Evaluation Result: " << result << endl;
		}
		catch (const std::runtime_error& error)
		{
			cout << "Error: " << error.what() << endl;
		}
	}

}