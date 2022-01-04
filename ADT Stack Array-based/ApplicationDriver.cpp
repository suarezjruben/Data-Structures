#include <iostream>
#include <string>
#include "ArrayStack.cpp"
using namespace std;

int main()
{

	ArrayStack<int> stack;
	ArrayStack<int> stack2;
	string expression, retryFlag;
	int result = 0;
	
	bool retry = true;

	int operand1 = 0;
	int operand2 = 0;

	while (retry)
	{
		bool exit = false;
		cout << "Enter postfix expression expression: ";
		getline(cin, expression);
		for (int i = 0; i < expression.length(); i++)
		{
			if (!exit)
			{
				switch (expression[i])
				{
				case '+':
					if (!stack.isEmpty())
					{
						operand2 = stack.peek();
						stack.pop();
						operand1 = stack.peek();
						stack.pop();
						result = operand1 + operand2;
						stack.push(result);
					}
					else
					{
						cout << "Error: The input expression is malformed! " << endl;
						exit = true;
					}
					
					break;
				case '-':
					if (!stack.isEmpty())
					{
						operand2 = stack.peek();
						stack.pop();
						operand1 = stack.peek();
						stack.pop();
						result = operand1 - operand2;
						stack.push(result);
					}
					else
					{
						cout << "Error: The input expression is malformed! " << endl;
						exit = true;
					}

					break;
				case '*':
					if (!stack.isEmpty())
					{
						operand2 = stack.peek();
						stack.pop();
						operand1 = stack.peek();
						stack.pop();
						result = operand1 * operand2;
						stack.push(result);
					}
					else
					{
						cout << "Error: The input expression is malformed! " << endl;
						exit = true;
					}

					break;
				case '/':
					if (!stack.isEmpty())
					{
						operand2 = stack.peek();
						stack.pop();
						operand1 = stack.peek();
						stack.pop();
						result = operand1 / operand2;
						stack.push(result);
					}
					else
					{
						cout << "Error: The input expression is malformed! " << endl;
						exit = true;
					}

					break;
				default:
					// If character is an integer number, push to stack.
					if (isdigit(expression[i]))
					{
						cout << "Pushing: " << expression[i] << endl;
						stack.push(expression[i] - '0');
					}
					// else if character does not belong, print error message.
					else
					{
						cout << "Error: Invalid character has been encountered! Exiting the calculation.." << endl;
						while (!stack.isEmpty())
						{
							stack.pop();
						}
						exit = true;
					}
					break;
				}
			}
			else
				break;

		}

		if (!stack.isEmpty())
		{
			result = stack.peek();
			cout << "The value of the expression is: " << result << endl;
		}
		else if (!exit)
		{
			cout << "The input expression is malformed! " << endl;
		}
			


		cout << "\nWould you like to try gain? Y/N: ";
		getline(cin, retryFlag);
		if (retryFlag == "N" || retryFlag == "n")
			retry = false;
		else
			cout << "Great!" << endl << endl;
	}
	return 0;
}  // end driver
