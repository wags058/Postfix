
# Postfix

## Overview
`Postfix` is a C++ program designed to:
- Convert mathematical expressions from infix notation (e.g., `(a+b)*c`) to postfix notation (`ab+c*`).
- Evaluate postfix expressions using integer variables (`a` to `f`).
- Load variable values from a text file, manage them, and view or evaluate expressions interactively.

This project demonstrates the use of custom data structures like a linked stack (`LinkedStack`) and a queue (`OurQueue`), as well as standard library utilities.

## Features
- **Infix to Postfix Conversion**: Converts infix expressions into postfix notation.
- **Postfix Evaluation**: Evaluates postfix expressions using assigned integer values for variables.
- **File Integration**: Reads variable values from a file for expression evaluation.
- **Error Handling**: Handles invalid input, division by zero, and missing variables.

## Setup and Compilation
### Visual Studio
1. Open the project in Visual Studio.
2. Exclude unnecessary `.cpp` files from the build (e.g., `Node.cpp`, `LinkedStack.cpp`, etc.).
3. Build and run the program.

### Command Line
1. Navigate to the project directory:
   ```bash
   cd path/to/project
   ```
2. Compile using `g++`:
   ```bash
   g++ -o Postfix main.cpp
   ```
3. Run the program:
   ```bash
   ./Postfix
   ```

## Usage
1. Load variable values from a file (`variables.txt`) containing six integers separated by spaces.
   ```cpp
   instance.readValuesFromFile("variables.txt");
   ```
2. Convert an infix expression to postfix:
   ```cpp
   instance.convertInfixToPostfix("(a+b)*c");
   ```
3. View the postfix expression:
   ```cpp
   std::cout << instance.getPostfixExpression() << std::endl;
   ```
4. Evaluate the postfix expression:
   ```cpp
   double result = instance.evaluatePostfixExpression();
   ```

## Example
For the input file `variables.txt`:
```
5 5 15 10 20 25
```
and the expression `(a+b)*c`, the program will:
- Convert to postfix: `ab+c*`
- Evaluate the result: `225`

## Future Enhancements
- Support for floating-point variables for real-number calculations.
- Support for additional operators, such as exponentiation.
- Ability to handle more variables (e.g., `a-z` instead of `a-f`).

## License
This project is open-source and available under the MIT license.
