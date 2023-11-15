#include <iomanip>
#include <array>
#include "Algorithms.h"

int UserInput( char type)
{
    int input = 0;

    do {
        cout << "Please enter your " << type << " = ";
        cin >> input;
        if (!cin) {
            cout <<endl << "Not a proper value! Please insert again";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> input;
        }
        if (cin)
            break;
    } while (true);

    return input;
}

void writeEuklides(const array<findinverse,20> & array) {

    cout << endl << setw(7) << setfill(' ') << array[0].rest << setw(3) << setfill(' ') << "| " << setw(4) << setfill(' ') << array[0].One
        << setw(4) << setfill(' ') << array[0].Two << "   | " << endl;
    cout << setw(7) << setfill(' ') << array[1].rest << setw(3) << setfill(' ') << "| " << setw(4) << setfill(' ') << array[1].One
        << setw(4) << setfill(' ') << array[1].Two << "   | " << array[2].Quota << endl << "   -------------------" << endl;

    for (int i = 2; i < 20; i++)
    {
        cout << setw(7) << setfill(' ') << array[i].rest << setw(3) << setfill(' ') << "| " << setw(4) << setfill(' ') << array[i].One
            << setw(4) << setfill(' ') << array[i].Two << "   | ";

        if (array[i+1].Quota != 0)
        {
            cout << array[i+1].Quota;
        }
        cout << endl;

        if (array[i].rest == 0) {
            if ((array[i].One*-1) == array[1].rest) {
                cout << endl << "The inverse of X is " << array[i - 1].Two << endl;
            }
            if ((array[i].Two * -1) == array[1].rest) {
                cout << endl << "The inverse of X is " << array[i - 1].One << endl;
            }
         break;
        }
    }
}

void check_gcd(const array <findinverse,20>& array)
{
    int gcd = lcd(array[0].rest, array[1].rest);

    if (gcd != 1) {
        cout << endl << "Because gcd of (" << array[0].rest << ", " << array[1].rest << ") is " << gcd << ". X has no inverse." << endl;
    }
    else
        cout << endl << "gcd (" << array[0].rest << ", " << array[1].rest << ") = " << gcd << endl;
}



void findinversecalculator() {

    int nIDX = 2;
    findinverse newElementA;
    findinverse newElementB;
    newElementB.x = UserInput('x');
    newElementA.y = UserInput('y');

    array<findinverse,20> arrayA;
    newElementA.One = 1; newElementA.Two = 0; newElementA.rest = newElementA.y;
    newElementB.One = 0; newElementB.Two = 1; newElementB.rest = newElementB.x;
    arrayA[0] = newElementA; arrayA[1] = newElementB;

    do {
        findinverse newElement;
        newElement.rest = (arrayA[nIDX - 2].rest % arrayA[nIDX - 1].rest);
        newElement.Quota = ((arrayA[nIDX - 2].rest / arrayA[nIDX - 1].rest)*-1);
        newElement.One = (arrayA[nIDX - 2].One + (newElement.Quota * arrayA[nIDX - 1].One));
        newElement.Two = (arrayA[nIDX - 2].Two + (newElement.Quota * arrayA[nIDX - 1].Two));
        arrayA[nIDX] = newElement;

        if (arrayA[nIDX].rest == 0) {
            break;
        }
        nIDX++;

    } while (true);

    check_gcd(arrayA);
    writeEuklides(arrayA);
}
