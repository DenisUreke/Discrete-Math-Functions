#include <iostream>

using namespace std;

void lcd() {

    int nFirst, nSecond, nMax;
    int nMultiplier = 1;

    cout << "Please enter your two numbers: ";
    cin >> nFirst >> nSecond;

    nMax = (nFirst > nSecond) ? nFirst : nSecond;

    int nNon_Changed_Max = nMax;


    while (true)
    {
        if (nMax % nFirst == 0 && nMax % nSecond == 0) {
            cout << "LCM is = " << nMax << endl;;
            break;
        }
        else {
            nMax = nNon_Changed_Max;
            nMax = nMax * nMultiplier;
            nMultiplier++;
        }
    };

    nMax = (nFirst < nSecond) ? nFirst : nSecond;

    do
    {
        if (nFirst % nMax == 0 && nSecond % nMax == 0) {
            cout << "GCD is = " << nMax << endl;
            break;
        }
        if (nMax == 1) {
            cout << "GCD is = " << nMax << endl;
            break;
        }
        else {
            nMax -= 1;
        }
    } while (true);
}
