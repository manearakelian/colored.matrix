#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>  // Include for Windows API functions
#include <cstdlib>    // Include for rand()

using namespace std;

void printColoredNumber(int number) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (number == 0) {
        // Set text color to red for 0
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    }
    else {
        // Set text color to green for non-zero numbers
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    }

    cout << setw(5) << number;

    // Reset color to default after printing the number
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int main() {
    cout << "input n:";
    int n;
    cin >> n;

    while (n < 3 || n > 100) {
        cout << "Size of matrix must be in range [3, 100]";
        cin >> n;
        cout << endl;
    }

    srand(time(0));
    int matrix[10][10];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 7 - 3;
            printColoredNumber(matrix[i][j]);
        }
        cout << endl;
    }

    cout << endl;

    int printed_lines[10] = { 0 };

    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n; j++) {
            if (matrix[j][j - i] == 0 && printed_lines[j] == 0) {
                printed_lines[j] = 1;
                for (int k = 0; k < n; k++) {
                    Sleep(1000);  // Sleep for 1 second on Windows
                    printColoredNumber(matrix[j][k]);
                }
                cout << endl;
            }
            if (matrix[j - i][j] == 0 && printed_lines[j - i] == 0) {
                printed_lines[j - i] = 1;
                for (int k = 0; k < n; k++) {
                    Sleep(1000);  // Sleep for 1 second on Windows
                    printColoredNumber(matrix[j - i][k]);
                }
                cout << endl;
            }
        }
    }

    return 0;
}

