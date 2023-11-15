#include "Algorithms.h"

ChangeBase::ChangeBase() {

    nOldBase = 0;
    nNewBase = 0;
    nRest = 0;
    nQuota = 9999;
}

void ChangeBase1() {

    ChangeBase arr[20];
    int i = 0;
    int iIDX = 0;


    do {
        std::cout << "Please enter Value you want to convert " << endl;
        cin >> arr[i].nOldBase;
        if (!cin) {
            std::cout << "Not a proper value! Please insert again" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> arr[i].nOldBase;
        }
        if (cin)
            break;
    } while (true);

    do {
        std::cout << "Please enter the Base you want to convert to " << endl;
        cin >> arr[i].nNewBase;
        if (!cin) {
            std::cout << "Not a proper value! Please insert again" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> arr[i].nNewBase;
        }
        if (cin)
            break;
    } while (true);

    do {

        arr[i].nQuota = (arr[i].nOldBase / arr[i].nNewBase);
        arr[i].nRest = (arr[i].nOldBase - (arr[i].nNewBase * arr[i].nQuota));
        arr[i + 1].nOldBase = arr[i].nQuota;
        arr[i + 1].nNewBase = arr[i].nNewBase;

        if (arr[i].nQuota == 0) {

            break;
        }
        i++;
        iIDX++;

    } while (true);

    std::cout << endl << "The visual of the algorithm is =" << endl << endl;

    for (int x = 0; x < sizeof(arr); x++)
    {
        if (arr[x].nQuota == 9999){
            break;
    }
        std::cout << arr[x].nOldBase << " = " << arr[x].nQuota << " X " << arr[x].nNewBase << " + " << arr[x].nRest << endl;
    }
    std::cout << endl << "The old former base 10 value of " << arr[0].nOldBase << " in the base of " << arr[0].nNewBase << " is = ";

    for (int x = iIDX; x >= 0; x--)
    {
        if (arr[x].nNewBase == 16 && arr[x].nRest >= 10) {

            if (arr[x].nRest == 10)
                cout << "a";
            if (arr[x].nRest == 11)
                cout << "b";
            if (arr[x].nRest == 12)
                cout << "c";
            if (arr[x].nRest == 13)
                cout << "d";
            if (arr[x].nRest == 14)
                cout << "e";
            if (arr[x].nRest == 15)
                cout << "f";
            continue;
        }

        std::cout << arr[x].nRest;
    }
    std::cout << endl << endl;
}
