#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int toOne(int spNum)
{
    int Tcnt1 = 0;
    int Tcnt2 = 0;
    int Tcnt3 = 0;
    int D[1000001];

    for (int i = 0; i < 1000001; i++)
    {
        D[i] = 0;
    }

    D[1] = 0;
    D[2] = 1;
    D[3] = 1;

    int togo = 0;

    for (int i = 4; i <= spNum; i++)
    {
        Tcnt1 = D[i - 1];

        if (i % 2 == 0 && i % 3 == 0)
        {

            Tcnt2 = D[i / 2];
            Tcnt3 = D[i / 3];
            togo = min({ Tcnt3,Tcnt2,Tcnt1 });

        }
        else if (i % 2 == 0) {

            Tcnt2 = D[i / 2];
            togo = min(Tcnt2, Tcnt1);

        }
        else if (i % 3 == 0) {

            Tcnt3 = D[i / 3];
            togo = min(Tcnt3, Tcnt1);

        }
        else {

            togo = Tcnt1;

        }

        D[i] = togo + 1;
        Tcnt1 = 0;
        Tcnt2 = 0;
        Tcnt3 = 0;
    }
    return D[spNum];
}

int main(void)
{
    int spNum = 0;
    int result = 0;

    cin >> spNum;
    result = toOne(spNum);
    cout << result;
    return 0;
}