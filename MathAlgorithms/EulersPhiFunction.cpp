#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int lcd(int nFirst, int nSecond) {

    int nMax = (nFirst < nSecond) ? nFirst : nSecond;

    do
    {
        if (nFirst % nMax == 0 && nSecond % nMax == 0) {
            return nMax;
            break;
        }
        if (nMax == 1) {
            return nMax;
            break;
        }
        else {
            nMax -= 1;
        }
    } while (true);
}

int UserInput()
{
    int input = 0;

    do {
        cout << "Please enter Value you want to check for " << endl;
        cin >> input;
        if (!cin) {
            cout << "Not a proper value! Please insert again" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> input;
        }
        if (cin)
            break;
    } while (true);

    return input;
}

void printValues(const vector<pair<int,int>>& vEulerVector, int count, int nUserInput) {

    int IDX = 0;

    cout << endl << "The multiplicative subset of " << nUserInput << " consists of " << count << " elements and those are: " << endl << endl;

    for (auto it = begin(vEulerVector); it != end(vEulerVector); it++) {

        if (it._Ptr->first == 1) {

            cout << setw(2) << it._Ptr->second << " ";
            IDX += 1;

            if ((IDX % 5 == 0) && IDX != 0) {
                cout << endl;
            }
        }
    }
    cout << endl;
}

void eulersPhiFunction()
{
    int nUserInput = UserInput();
    int count = 0;

    vector<pair<int,int>>vEulerVector;

    for (int i = 1; i < nUserInput; i++)
    {
        int subset = i;
        int gcd = 0;
        vEulerVector.push_back(make_pair(gcd,subset));
        vEulerVector.back().first = lcd(vEulerVector.back().second, nUserInput);
        if (vEulerVector.back().first == 1)
        {
            count += 1;
        }
    }
    printValues(vEulerVector, count, nUserInput);
}
