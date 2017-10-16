#include "accoutnplus.h"

AccoutnPlus::AccoutnPlus() : BasicAccount(), IsBeterThenBasic(true){

}

bool AccoutnPlus::GetFlag(){
    return IsBeterThenBasic;
}

bool AccoutnPlus::ShowDeps(const std::string name){
    bool tmp = BasicAccount::ShowDeps(name);
    cout << "is beter then basic: " << GetFlag() << endl;
    return tmp;
}
