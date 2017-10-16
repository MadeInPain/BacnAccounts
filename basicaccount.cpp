#include "basicaccount.h"




BasicAccount::BasicAccount(string member_name, int account_number, short max_deposits)
{
    name = member_name;
    acc_number = account_number;
    this->max_dep_count = max_deposits;
    pt = new deposit[max_dep_count];
    dep_count = 0;


}
BasicAccount::BasicAccount(){
    name = "noname";
    acc_number = 0;
    balance = 0;
    this->max_dep_count = 5;
    pt = new deposit[max_dep_count];

    dep_count = 0;
}

BasicAccount::~BasicAccount(){
    delete[] pt;
}

bool BasicAccount::isDepExist(std::string &name){
    for(int i = 0; i < dep_count; i++){
        if(pt[i].dep_name == name)
            return true;
    }
    return false;
}

bool BasicAccount::CreateDep(string name, double dep_balance) {
    if(dep_count <= 5 && !isDepExist(name)){
        pt[dep_count] = {name, dep_balance};
        ++dep_count;
        return true;
    }
    return false;
}

bool BasicAccount::FillDep(string dep_name, double add_money){
    for(int i = 0; i < dep_count; i++){
        if(pt[i].dep_name == dep_name){
            pt[i].dep_balance += add_money;
            return true;
        }
    }
    return false;
}

bool BasicAccount::ShowDeps(const std::string name ){
    bool res = false;
    cout << "Info: " << this->name << ", account number: " << this->acc_number << endl;
    if(name == ""){
        for(int i = 0; i < dep_count; i++){
            cout << "dep #" << i+1 << " :" << pt[i].dep_name << "| $" << pt[i].dep_balance << endl;
            res = true;
        }
        return res;
    }
    else{
        for(int i = 0; i < dep_count; i++){
            if(pt[i].dep_name == name){
                cout << "dep " << "name" << "| $" << pt[i].dep_balance << endl;
                res = true;
                return res;
            }
        }
    }
    return res;
}
