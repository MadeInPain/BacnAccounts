#include <iostream>
#include "basicaccount.h"

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
    cout << "program is working..." << endl;

    cout << "Usage:\n";
    cout << "C -create account\n";
    cout << "D -add deposit\n";
    cout << "F -fill deposit\n";
    cout << "I -show info\n";
    cout << "X -exit\n";

    cout << "Maximum accounts:" << MAX_CNT << endl;

    char a;
    BasicAccount *ptr = new BasicAccount[20];
    short cnt = 0;
    int itemp;
    string stemp;
    bool btemp;

    while(displayLegend(),cin >> a, (a != 'X') && (a != 'x')){
        switch (a) {
        case 'C':
        case 'c':
            if(cnt < MAX_CNT)
            cout << "Creating accout, cell # "<< cnt+1 <<", enter Name: ";
            //getline(cin, temp);
            cin >> stemp;
            ptr[cnt].SetName(stemp);
            cout << "Enter account number: ";
            cin >> itemp;
            ptr[cnt].SetAccNum(itemp);
            cnt++;
            break;
        case 'D':
        case 'd':
            cout << "Enter cell number(1-20): ", cin >> itemp;
            cout << "Enter Name: ", cin >> stemp;
            cout << "Enter Balance: ", cin >> itemp;
            btemp = ptr[itemp-1].CreateDep(stemp, itemp);
            if(btemp){
                cout << "Sucsesful!" <<endl;
            }
            else{
                cout << "Error!" << endl;
            }
            break;
        case 'F':
        case 'f':
            break;
        case 'I':
        case 'i':
            cout << "Enter cell number(1-20): ", cin >> itemp;
            ptr[itemp-1].ShowDeps();
            break;
        default:
            break;
        }
    }

    cout << "Exit\n";

    delete[] ptr;
    return 0;
}
