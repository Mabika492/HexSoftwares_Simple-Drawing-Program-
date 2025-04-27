#include <iostream>
#include <cmath>
using namespace std;

void drawRectangle(int width, int height, char ch) {
    cout << "\033[32m"; // Green
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << ch << " ";
        }
        cout << endl;
    }
    cout << "\033[0m"; // Reset
}

void drawTriangle(int height, char ch) {
    cout << "\033[31m"; // Red
    for (int i = 1; i <= height; i++) {
        for (int j = 0; j < i; j++) {
            cout << ch << " ";
        }
        cout << endl;
    }
    cout << "\033[0m";
}

void drawCircle(int radius, char ch) {
    cout << "\033[33m"; // Yellow
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            if (i * i + j * j <= radius * radius + radius) {
                cout << ch << " ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << "\033[0m";
}

void drawSideTriangle(int height, char ch) {
    cout << "\033[31m"; // Red
    for (int i = 1; i <= height; i++) {
        for (int j = 0; j < i; j++) {
            cout << ch << " ";
        }
        cout << endl;
    }
    for (int i = height - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            cout << ch << " ";
        }
        cout << endl;
    }
    cout << "\033[0m";
}

int main() {
    int choice, width, height, radius;
    char drawChar;
    bool running = true;

    while (running) {
        cout << "\nDRAWING SHAPES USING CHARACTERS" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Draw Rectangle" << endl;
        cout << "2. Draw Right-Angle Triangle " << endl;
        cout << "3. Draw Circle " << endl;
        cout << "4. Draw Side-to-Side Triangle" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter an option: ";
        
        cin >> choice;

        if (choice == 5) {
            cout << "Goodbye!" << endl;
            break;
        }

        cout << "Enter the character to draw with: ";
        cin >> drawChar;

        switch (choice) {
            case 1:
                cout << "Enter width: ";
                cin >> width;
                cout << "Enter height: ";
                cin >> height;
                drawRectangle(width, height, drawChar);
                break;
            case 2:
                cout << "Enter height: ";
                cin >> height;
                drawTriangle(height, drawChar);
                break;
            case 3:
                cout << "Enter radius: ";
                cin >> radius;
                drawCircle(radius, drawChar);
                break;
            case 4:
                cout << "Enter height: ";
                cin >> height;
                drawSideTriangle(height, drawChar);
                break;
            default:
                cout << "Invalid choice. Please choose 1 to 5." << endl;
        }
    }

    return 0;
}
    