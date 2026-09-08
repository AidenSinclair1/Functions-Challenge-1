/*
Name: Aiden Sinclair
Date: September 6, 2026
Program: Functions Challenge 1
Purpose:
This program uses overloaded functions to calculate the area
and perimeter of circles and rectangles. It uses a menu-driven
interface with input validation.
*/
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;


double calculateArea(const double radius);
double calculateArea(const double length, const double width);

double calculatePerimeter(const double radius);
double calculatePerimeter(const double length, const double width);

double getPositiveNumber(const string& prompt);
int getMenuChoice();

int main() {
    int choice;

    do {
        cout << "\n===== Geometric Calculations =====\n";
        cout << "1. Area of a Circle\n";
        cout << "2. Perimeter of a Circle\n";
        cout << "3. Area of a Rectangle\n";
        cout << "4. Perimeter of a Rectangle\n";
        cout << "5. Quit\n";

        choice = getMenuChoice();

        switch (choice) {
            case 1: {
                double radius = getPositiveNumber("Enter the radius: ");
                cout << "Area of the circle: " << calculateArea(radius) << endl;
                break;
            }

            case 2: {
                double radius = getPositiveNumber("Enter the radius: ");
                cout << "Perimeter of the circle: "
                     << calculatePerimeter(radius) << endl;
                break;
            }

            case 3: {
                double length = getPositiveNumber("Enter the length: ");
                double width = getPositiveNumber("Enter the width: ");

                cout << "Area of the rectangle: "
                     << calculateArea(length, width) << endl;
                break;
            }

            case 4: {
                double length = getPositiveNumber("Enter the length: ");
                double width = getPositiveNumber("Enter the width: ");

                cout << "Perimeter of the rectangle: "
                     << calculatePerimeter(length, width) << endl;
                break;
            }

            case 5:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid menu choice.\n";
        }

    } while (choice != 5);

    return 0;
}


double calculateArea(const double radius) {
    const double PI = 3.14159;
    return PI * radius * radius;
}


double calculateArea(const double length, const double width) {
    return length * width;
}


double calculatePerimeter(const double radius) {
    const double PI = 3.14159;
    return 2 * PI * radius;
}


double calculatePerimeter(const double length, const double width) {
    return 2 * (length + width);
}


double getPositiveNumber(const string& prompt) {
    double number;

    while (true) {
        cout << prompt;
        cin >> number;

        if (cin.fail() || number <= 0) {
            cout << "Invalid input. Please enter a positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return number;
        }
    }
}

int getMenuChoice() {
    int choice;

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 5) {
            cout << "Invalid choice. Please enter a number from 1 to 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return choice;
        }
    }
}
