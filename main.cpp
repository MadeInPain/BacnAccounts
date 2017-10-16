#include <iostream>
#include "basicaccount.h"
#include "accoutnplus.h"

#define MAX_CNT 20
using namespace std;
int count = 0;

void use(bool a){
    if(!a)
        cout << count++ << "# error" << endl;
    else
        cout << count++ << "# done" << endl;
}
void displayLegend(){
    cout << "waiting for input (C, D, F, I, X): ..." << endl;
}

int main()
{
    BasicAccount MyAcc("viktor bliakhovskyi", 2228200);
    MyAcc.CreateDep("zarplata");
    MyAcc.FillDep("zarplata", 100);
    MyAcc.ShowDeps();
    MyAcc.ShowDeps("zarplata");

    MyAcc.FillDep("zp", 10);

    MyAcc.CreateDep("zanachka", 200);

    MyAcc.ShowDeps("zanachka");

    AccoutnPlus BetterAcc;
    BetterAcc.ShowDeps();

    BasicAccount *pt = new AccoutnPlus;
    pt->ShowDeps();

    return 0;
}
