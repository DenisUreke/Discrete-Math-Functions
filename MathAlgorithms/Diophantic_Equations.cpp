#include <iomanip>
#include <cctype>
#include <array>
#include "Algorithms.h"


char* userInput(char(&input)[25])
{

    do {
        cout << "Please enter your equation = ";
        cin.getline(input, 25);
        if (!cin) {
            cout << endl << "Please try inserting again =";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> input;
        }
        if (cin)
            break;
    } while (true);

    return input;
}

findinverse convertString(const char(&userInput)[25]) {

    int count = 0;
    int countDecimals = 0;
    findinverse converted;

    for (int i = 0; i < 25; i++)
    {
        if (isdigit(userInput[i])) {
            while (true) {

                if (isalpha(userInput[countDecimals + i]) || userInput[countDecimals + i] == '\0' || isspace(userInput[countDecimals + i])) {
                    break;
                }
                countDecimals++;
            }
            if (count == 0) {
                converted.x += ((userInput[i] - '0') * (pow(10, countDecimals - 1)));
                countDecimals = 0;
            }
            if (count == 1) {
                converted.y += ((userInput[i] - '0') * (pow(10, countDecimals - 1)));
                countDecimals = 0;
            }
            if (count == 2) {
                converted.result += ((userInput[i] - '0') * (pow(10, countDecimals - 1)));
                countDecimals = 0;
            }
        }
        if ((toupper(userInput[i]) == 'X') || toupper(userInput[i]) == 'Y'){
            count++;
            continue;
        }
        if (userInput[i] == '+'|| userInput[i] == '-') {
            converted.sign += userInput[i];
            continue;
        }
    }
    return converted;
}

void tryequation() {
    findinverse a;
    char b[25] = {};
    userInput(b);
    a = convertString(b);



    cout << endl << "x is = " << a.x << endl << "y is " << a.y << endl << "sign is = " << a.sign << endl << "result is = " << a.result << endl;
}


