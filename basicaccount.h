#ifndef BASICACCOUNT_H
#define BASICACCOUNT_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

struct deposit {
    string dep_name;
    double dep_balance;
};

class BasicAccount
{
protected:
    string name;
    int acc_number;
    double balance;
    deposit *pt;
    short dep_count;
    short max_dep_count;

    bool isDepExist(string &name);

    //set
    void SetName(string name){this->name = name;}
    void SetAccNum(int acc_number){this->acc_number = acc_number;}
public:
    BasicAccount(string member_name, int accout_number, short max_deposits = 5);
    BasicAccount();
    ~BasicAccount();



    bool CreateDep(string name, double dep_balance = 0);
    bool FillDep(string name, double add_money);
    virtual bool ShowDeps(const string name = "");


};

#endif // BASICACCOUNT_H
