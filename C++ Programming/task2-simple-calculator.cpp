#include <iostream>

using namespace std;

int main() {
    double num1, num2, result;
    char operation;
    bool tryAgain;

    do {
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;

        cout << "Choose an operation (+, -, *, /): ";
        cin >> operation;

        switch (operation) {
            case '+':
                result = num1 + num2;
                cout << "Result of " << num1 << " + " << num2 << " = " << result << endl;
                break;
            case '-':
                result = num1 - num2;
                cout << "Result of " << num1 << " - " << num2 << " = " << result << endl;
                break;
            case '*':
                result = num1 * num2;
                cout << "Result of " << num1 << " * " << num2 << " = " << result << endl;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "Result of " << num1 << " / " << num2 << " = " << result << endl;
                } else {
                    cout << "Error! Division by zero is not allowed." << endl;
                }
                break;
            default:
                cout << "Invalid operation! Please choose from +, -, *, /." << endl;
        }

        char choice;
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;
        tryAgain = (choice == 'y' || choice == 'Y');

    } while (tryAgain);

    cout << "Thank you for using the calculator. Goodbye!" << endl;

    return 0;
}
