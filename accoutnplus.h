#ifndef ACCOUTNPLUS_H
#define ACCOUTNPLUS_H

#include "basicaccount.h"


class AccoutnPlus : public BasicAccount
{
private:
    bool IsBeterThenBasic;
    bool GetFlag();
public:
    AccoutnPlus();
    virtual ~AccoutnPlus(){}

    bool ShowDeps(const std::string name = "");

};

#endif // ACCOUTNPLUS_H
