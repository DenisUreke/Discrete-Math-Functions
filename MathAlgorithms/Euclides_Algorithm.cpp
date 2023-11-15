#include "Algorithms.h"

using namespace std;

//Euclides Algorithm ----------------------------------------------------------------------------------------------------------------------------------------------

Equation_Lines::Equation_Lines()
{
    a = 0;
    b = 0;
    multiplier = 0;
    rest = 0;
    size = -1;
}

Equation_Lines_Extended::Equation_Lines_Extended()
{
    multiplier_one = 1;
    multiplier_two = 1;
    a = 0;
    b = 0;
}

void Solve_Equation(Equation_Lines* pointer)  // Solves diophantine equations
{
    Equation_Lines_Extended Extended_Lines;
    Extended_Lines.a = pointer[pointer[0].size - 1].a;
    Extended_Lines.b = pointer[pointer[0].size - 1].b;
    Extended_Lines.multiplier_two = pointer[pointer[0].size - 1].multiplier;
    int values[3]{};
    string questions[3] = { "Please insert the multiple for X ", "Please insert the multiple for Y ", "Please insert the sum (equals to) " };
    int j = 0;
    cout << "\n";

    while (true)
    {
        if (j == 3)
        {
            break;
        }

        cout << questions[j];
        cin >> values[j];
        j++;

        if ((!cin >> values[j]))
        {
            cin.clear();
            cin.ignore();
            system("cls");
            j--;
            continue;
        }
    }

    cout << "\n" << "Extended Euclides Algorithm" << "\n" << "\n" << pointer[pointer[0].size - 1].rest << " = " << pointer[pointer[0].size - 1].a << " + " << "( " << pointer[pointer[0].size - 1].multiplier << " ) * " << pointer[pointer[0].size - 1].b << "\n";

    for (int i = pointer[0].size -1; i > 0; i-=1) // loop where the extended algorithm is run
    {
        if (Extended_Lines.a == pointer[i - 1].rest)
        {
            Extended_Lines.a = pointer[i - 1].a;
            Extended_Lines.multiplier_two = (((Extended_Lines.multiplier_one * pointer[i - 1].multiplier * pointer[i - 1].b) + (Extended_Lines.multiplier_two * Extended_Lines.b)) / Extended_Lines.b);
        }

        else if (Extended_Lines.b == pointer[i - 1].rest)
        {
            Extended_Lines.multiplier_one += ((Extended_Lines.multiplier_two * pointer[i - 1].multiplier * pointer[i - 1].b) / pointer[i - 1].b);
            Extended_Lines.b = pointer[i - 1].a;
        }

        cout << Extended_Lines.multiplier_one << " * " << Extended_Lines.a << " + " << Extended_Lines.multiplier_two << " * " << Extended_Lines.b << "\n";
    }

    if (values[0] > values[1]) // if statements to ensure X and Y are in the right order when written out
    {
        cout << "\n" << "X = " << Extended_Lines.multiplier_one * values[2] << " , " << "Y = " << Extended_Lines.multiplier_two * values[2] << "\n";
    }
    else if (values[0] < values[1])
    {
        cout << "\n" << "X = " << Extended_Lines.multiplier_two * values[2] << " , " << "Y = " << Extended_Lines.multiplier_one * values[2] << "\n";
    }
}

Equation_Lines* Reversed_Euclides_Algorithm(Equation_Lines* pointer) // Used to prepare for diophantine equations
{
    cout << "\n" << "\n";
    for (int i = 0; i < pointer[0].size; i++)
    {
        if (pointer[i].rest == 0)
        {
            break;
        }
        else
        {
            pointer[i].multiplier -= (pointer[i].multiplier * 2); // reverse value
            cout << pointer[i].rest << " = " << pointer[i].a << " + " << "( " << pointer[i].multiplier << " ) * " << pointer[i].b << "\n";
        }
    }

    return pointer;

}

Equation_Lines* Find_Largest_Common_Denominator()
{
    int a = 0, b = 0, c = 0, d = 0;

    while (true)
    {
        cout << "Please insert the value of A (higher value) ";
        cin >> a;

        if ((!cin >> a))
        {
            cin.clear();
            cin.ignore();
            system("cls");
            continue;
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        cout << "Please insert the value of B (lower value) ";
        cin >> b;

        if (!cin >> b)
        {
            cin.clear();
            cin.ignore();
            system("cls");
            continue;
        }
        else
        {
            cout << "\n";
            break;
        }
    }

    int multiple = a * b;
    int IDX = 0;
    int iteration = 1;
    Equation_Lines* cout_lines = new Equation_Lines[20];

    while (true)
    {
        c = a % b;
        while (true)
        {
            if (((b * iteration) + c) == a)
            {
                cout_lines[IDX].a = a;
                cout_lines[IDX].b = b;
                cout_lines[IDX].multiplier = iteration;
                cout_lines[IDX].rest = c;
                cout << cout_lines[IDX].a << " = " << cout_lines[IDX].multiplier << " * " << cout_lines[IDX].b << " + " << cout_lines[IDX].rest << "\n";
                cout_lines[0].size += 1;
                IDX++;
                iteration = 0;
                break;
            }
            iteration++;
        }
        if (c != 0) // if there is still reaming vakue move digits to continue loop
        {
            a = b;
            b = c;
            d = c;
        }
        else
        {
            cout << "\n" << "The highest common denominator is = " << d << "\n";
            cout << "The smallest common multiple is = " << multiple / d;
            break;
        }
    }
    return cout_lines;
}
